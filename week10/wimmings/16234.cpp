#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

int n, L, R;
int map[52][52];
bool visited[52][52];


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool open(int x, int y, int nx, int ny) {
    int diff = abs(map[x][y] - map[nx][ny]);
    return diff >= L && diff <= R;
}

int bfs(int r, int c) {
    queue<pii> q;
    vector<pii> v;

    q.push({r, c});
    v.push_back({r, c});

    visited[r][c] = 1;
    int sum = 0;
    int flag = false;

    while (!q.empty()) {
        pii now = q.front();
        sum += map[now.first][now.second];
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny] || !open(now.first, now.second, nx, ny)) continue;

            flag = true;
            visited[nx][ny] = 1;
            q.push({nx, ny});
            v.push_back({nx, ny});
        }
    }

    if (flag) { // 인구 이동 있다
        int avg = sum / v.size();
        for (int i = 0; i < v.size(); ++i) {
            map[v[i].first][v[i].second] = avg;
        }
        return 1;
    }
    else { // 없다
        return -1;
    }

}
int ans;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> L >> R;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
        }
    }
    bool move = false;
    
    for (; ; ) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j]) continue;
                int res = bfs(i, j);
                if (res == -1) continue; // 한 번이라도 인구이동 발생해서 bfs 값이 -1이 아니라면 move가 true.
                move = true;
            }
        }
        if (move) ans++;
        else break;
        memset(visited, 0, sizeof(visited));
        move = false;
    }
    cout << ans << '\n';
    
    return 0;
}