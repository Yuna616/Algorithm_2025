#include <iostream>
using namespace std;

#define MARK 1
#define UNMARK 0
#define MAXSIZE 30

typedef struct Point { int x, y; } point;

point direction[8] = {
    {1,-2}, {2,-1}, {2,1}, {1,2},
    {-1,2}, {-2,1}, {-2,-1}, {-1,-2}
};

int board[MAXSIZE][MAXSIZE], path[MAXSIZE][MAXSIZE];

int knightTour(int m, int n, point pos, int counter) {
    if (counter == m * n) {
        return 1;
    }

    for (int i = 0; i < 8; i++) {
        point next;
        next.x = pos.x + direction[i].x;
        next.y = pos.y + direction[i].y;

        if (next.x > 0 && next.x <= n && next.y > 0 && next.y <= m
            && board[next.y][next.x] != MARK) {
            board[next.y][next.x] = MARK;
            path[next.y][next.x] = counter + 1;

            if (knightTour(m, n, next, counter + 1)) {
                return 1;
            }

            board[next.y][next.x] = UNMARK;
            path[next.y][next.x] = 0;
        }
    }
    return 0;
}

void printTour(int m, int n) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << path[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        int m, n, a, b;
        cin >> m >> n >> a >> b;
        point start;
        start.y = a;
        start.x = b;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                board[i][j] = UNMARK;
                path[i][j] = 0;
            }
        }
        board[start.y][start.x] = MARK;
        path[start.y][start.x] = 1;

        if (knightTour(m, n, start, 1)) {
            cout << 1 << "\n";
            printTour(m, n);
        }
        else {
            cout << "0" << "\n";
        }
    }
}
