# mini_serv — Exam 06 (42 School)

A TCP chat server. Clients connect, get an ID, and can send messages to each other.
The server relays everything — it never prints anything itself.

---

## How to compile and test

```bash
gcc -Wall -o my_serv my_serv.c

# Terminal 1 — server (stays silent)
./my_serv 4242

# Terminal 2 — client 0
nc 127.0.0.1 4242

# Terminal 3 — client 1
nc 127.0.0.1 4242
```

Type in Terminal 2, see the message in Terminal 3 as `client 0: your message`.
When Terminal 3 connects, Terminal 2 sees `server: client 1 just arrived`.

---

## Global variables

```c
int    max_fd;              // highest fd currently open
int    server_fd;           // the listening socket fd
fd_set all_fds;             // all active fds (server + clients)
fd_set write_fds;           // snapshot used by select() each iteration
int    client_id[65536];    // maps fd → client number (0, 1, 2, ...)
char  *client_buf[65536];   // maps fd → incomplete line buffer (or NULL)
int    g_id = 0;            // auto-incrementing client ID counter
char   msg_buf[200000];     // scratch buffer for building outgoing messages
```

`client_id` and `client_buf` are indexed by fd, not by client number.
Global arrays are zero-initialized, so `client_buf` starts as all NULL.

---

## Functions

### `fatal()`
Writes `"Fatal error\n"` to stderr and exits with code 1.
Called when `socket`, `bind`, `listen`, or `realloc` fail.

### `send_all(int except, char *msg)`
Sends `msg` to every client that is:
- in `write_fds` (ready to receive, won't block)
- not `server_fd`
- not `except` (the sender, or the newly connected/disconnected client)

Using `write_fds` is what keeps the server non-blocking even when a client is slow to read — we skip them instead of blocking or disconnecting them.

---

## Main loop — step by step

### Setup (runs once)
```
socket() → bzero/fill addr → bind() → listen()
FD_ZERO(&all_fds) → FD_SET(server_fd) → max_fd = server_fd
```

### Event loop (runs forever)
```
read_fds = write_fds = all_fds      ← snapshot before select modifies them
select(max_fd + 1, &read_fds, &write_fds, NULL, NULL)
iterate fd 0..max_fd, find first fd set in read_fds
```

### Case 1: fd == server_fd → new client
```
accept() → FD_SET(client, &all_fds) → update max_fd
client_id[client] = g_id++
client_buf[client] = NULL
sprintf "server: client %d just arrived\n"
send_all(client, msg)       ← exclude new client itself
break
```

### Case 2: recv() <= 0 → client disconnected
```
sprintf "server: client %d just left\n"
FD_CLR(fd, &all_fds) → free(client_buf[fd]) → close(fd)
send_all(fd, msg)           ← fd already removed, exclude is redundant but harmless
break
```

### Case 3: recv() > 0 → message received
```
tmp[n] = '\0'
realloc client_buf[fd] to fit new data
memcpy new data onto end of client_buf[fd]

loop: find '\n' with strchr
    *nl = '\0'
    sprintf "client %d: %s\n"
    send_all(fd, msg)
    start = nl + 1

if leftover (no \n at end): memmove remainder to front of buffer
else: free buffer, set NULL
break
```

---

## Why `break` after every event?

After a new connection, `max_fd` may have changed — the loop bound is stale.
After a disconnect, `all_fds` changed.
Breaking and re-running `select` keeps state consistent.

---

## Why two fd sets (`all_fds` and `write_fds`)?

`select()` **modifies** the fd sets you pass in — it clears fds that aren't ready.
So you pass **copies** (`read_fds`, `write_fds`) and keep `all_fds` untouched as the master list.

---

## Why buffer per client (`client_buf`)?

A single `recv()` can return half a line. The next `recv()` returns the rest.
You must accumulate data until you see `\n`, then forward the complete line.
Without a per-client buffer you'd forward incomplete lines or corrupt messages.

---

## Common mistakes to avoid

| Mistake | Fix |
|---|---|
| Passing `all_fds` directly to `select` | Always copy to `read_fds`/`write_fds` first |
| Sending to `server_fd` | `send_all` explicitly skips it |
| Forgetting `tmp[n] = '\0'` | `strchr` and `strlen` need null terminator |
| `memcpy` wrong size | Copy `n + 1` bytes (includes `'\0'`) |
| Not freeing `client_buf` on disconnect | Memory leak — free it before `close` |
| Running two server instances on same port | Second `bind` fails → "Fatal error" — use a different port |

---

## Exam reconstruction order

1. Includes + globals (7 globals, memorize their types)
2. `fatal()` — 2 lines
3. `send_all()` — 1 loop, 3 conditions
4. `main()` — argument check, socket setup, init fd sets
5. Event loop — select, for loop, 3 cases in order: new client / disconnect / message
6. Message case last — it's the longest but follows the pattern: recv → buffer → split → send
