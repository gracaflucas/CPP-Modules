#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    if (argc != 4)
        return 1;

    int w = atoi(argv[1]);
    int h = atoi(argv[2]);
    int iter = atoi(argv[3]);

    if (w <= 0 || h <= 0 || iter < 0)
        return 1;

    int grid[2][h + 2][w + 2];
    for (int i = 0; i < 2; i++) {
        for (int y = 0; y < h + 2; y++) {
            for (int x = 0; x < w + 2; x++) {
                grid[i][y][x] = 0;
            }
        }
    }

    int x = 1;
    int y = 1;
    int pen = 0;
    char in;

    while (read(0, &in, 1) > 0) {
        if (in == 'w' && y > 1)
            y--;
        else if (in == 's' && y < h)
            y++;
        else if (in == 'a' && x > 1)
            x--;
        else if (in == 'd' && x < w)
            x++;
        else if (in == 'x')
            pen = !pen;
        if (pen)
            grid[0][y][x] = 1;
    }

    for (int t = 0; t < iter; t++) {
        int cur = t % 2;
        int next = !cur;
        for (int y = 1; y <= h; y++) {
            for (int x = 1; x <= w; x++) {
                int nb = 0;
                for (int c = 0; c < 9; c++) {
                    nb += grid[cur][y + (c / 3) - 1][x + (c % 3) - 1];
                }
                grid[next][y][x] = (nb == 3) | (nb == 4 && grid[cur][y][x]);
            }
        }
    }

    for (int y = 1; y <= h; y++) {
        for (int x = 1; x <= w; x++) {
            putchar(grid[iter % 2][y][x] ? 'O' : ' ');
        }
        putchar('\n');
    }
    return 0;
}