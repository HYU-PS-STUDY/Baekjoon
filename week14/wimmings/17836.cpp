#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

int n, m, t;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int map[102][102];
int ans = (1<<30);
int visited[102][102];
// 공주위치 : n-1, m-1

int bfs(int r, int c) {
    fill(&visited[0][0], &visited[101][102], -1);

    visited[r][c] = 0;
    queue<pii> q;
    q.push({r, c});

    while (!q.empty()) {
        pii now = q.front();
        q.pop();
        if (map[now.first][now.second] == 2) {
            int dist = visited[now.first][now.second] + n-1 - now.first + m-1 - now.second; // 검~공주 거리 더하기
            ans = min(ans, dist);
        }
        if (now.first== n-1 && now.second == m-1) {
            ans = min(ans, visited[now.first][now.second]);
            break;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n ||ny >= m) continue;
            if (map[nx][ny] == 1 || visited[nx][ny] >= 0) continue;
            visited[nx][ny] = visited[now.first][now.second] + 1;
            q.push({nx, ny});
        }
    }

    if (ans <= t) return ans;
    else return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }
    int res = bfs(0, 0);
    if (res == -1) cout << "Fail" << '\n';
    else cout << res << '\n';

    return 0;
}