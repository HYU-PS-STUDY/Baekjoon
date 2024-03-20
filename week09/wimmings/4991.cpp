#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, state, dist;
};

int start_x, start_y;
int dust_num;
int r, c;

int room[22][22];
bool visited[22][22][1<<10];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs() {
    queue<Point> q;
    q.push({start_x, start_y, 0, 0});

    while (!q.empty()) {
        Point now = q.front();
        q.pop();

        if (now.state == (1 << dust_num)-1) {
            return now.dist;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            int state = now.state;

            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (room[nx][ny] == -1) continue;

            if (room[nx][ny] > 0) { // 먼지 있는 곳
                state |= (1 << (room[nx][ny]-1));
            }
            if (visited[nx][ny][state]) continue;

            visited[nx][ny][state] = 1;
            q.push({nx, ny, state, now.dist+1});
        }
    }
    return -1;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (; ; ) {
        cin >> c >> r;
        if (c == 0 && r == 0) break;
        memset(room, 0, sizeof(room));
        memset(visited, 0, sizeof(visited));

        dust_num = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                char ch; cin >> ch;
                if (ch == '*') {
                    room[i][j] = ++dust_num;
                }
                else if (ch == 'x') {
                    room[i][j] = -1;
                }
                else if (ch == 'o') {
                    start_x = i, start_y = j;
                }
            }
        }
        cout << bfs() << '\n';
    }

    return 0;
}