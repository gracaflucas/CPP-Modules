#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int     max_fd;
int     server_fd;
fd_set  all_fds;
fd_set  write_fds;
int     client_id[65536];
char    *client_buf[65536];
int     g_id = 0;
char    msg_buf[200000];

void fatal(void) {
    write(2, "Fatal error\n", 12);
    exit(1);
}

void send_all(int except, char *msg) {
    for (int fd = 0; fd <= max_fd; fd++)
        if (FD_ISSET(fd, &write_fds) && fd != server_fd && fd != except)
            send(fd, msg, strlen(msg), 0);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        write(2, "Wrong number of arguments\n", 26);
        exit(1);
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
        fatal();

    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(0x7F000001);  // 127.0.0.1
    addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        fatal();
    if (listen(server_fd, 10) < 0)
        fatal();

    FD_ZERO(&all_fds);
    FD_SET(server_fd, &all_fds);
    max_fd = server_fd;

    while (1) {
        fd_set read_fds = all_fds;
        write_fds = all_fds;
        if (select(max_fd + 1, &read_fds, &write_fds, NULL, NULL) < 0)
            continue;

        for (int fd = 0; fd <= max_fd; fd++) {
            if (!FD_ISSET(fd, &read_fds))
                continue;

            // New client connecting
            if (fd == server_fd) {
                int client = accept(server_fd, NULL, NULL);
                if (client < 0)
                    continue;
                FD_SET(client, &all_fds);
                if (client > max_fd)
                    max_fd = client;
                client_id[client] = g_id++;
                client_buf[client] = NULL;

                sprintf(msg_buf, "server: client %d just arrived\n", client_id[client]);
                send_all(client, msg_buf);
                break;
            }

            // Receive data from existing client
            char tmp[4096];
            int n = recv(fd, tmp, sizeof(tmp) - 1, 0);

            // Client disconnected
            if (n <= 0) {
                sprintf(msg_buf, "server: client %d just left\n", client_id[fd]);
                FD_CLR(fd, &all_fds);
                free(client_buf[fd]);
                client_buf[fd] = NULL;
                close(fd);
                send_all(fd, msg_buf);
                break;
            }
            tmp[n] = '\0';

            // Append received data to this client's buffer
            int old_len = client_buf[fd] ? strlen(client_buf[fd]) : 0;
            char *new_buf = realloc(client_buf[fd], old_len + n + 1);
            if (!new_buf)
                fatal();
            client_buf[fd] = new_buf;
            memcpy(client_buf[fd] + old_len, tmp, n + 1);

            // Send every complete line (terminated by \n) to all other clients
            char *start = client_buf[fd];
            char *nl;
            while ((nl = strchr(start, '\n'))) {
                *nl = '\0';
                sprintf(msg_buf, "client %d: %s\n", client_id[fd], start);
                send_all(fd, msg_buf);
                start = nl + 1;
            }

            // Keep any remaining partial line in the buffer
            int remaining = strlen(start);
            if (remaining > 0)
                memmove(client_buf[fd], start, remaining + 1);
            else {
                free(client_buf[fd]);
                client_buf[fd] = NULL;
            }
            break;
        }
    }
    return 0;
}