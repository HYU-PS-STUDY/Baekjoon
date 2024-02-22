#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>
#include <queue>


using namespace std;

int m, n;
int map[502][502];
int ans[502][502];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

priority_queue<pair<int, pair<int, int>>> pq;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
        }
    }
    ans[0][0] = 1;
    if (1 < n && map[0][1] < map[0][0]) pq.push({map[0][1], {0, 1}});
    if (1 < m && map[1][0] < map[0][0]) pq.push({map[1][0], {1, 0}});

    while (!pq.empty()) {
        int now = pq.top().first;
        pair<int, int> pos = pq.top().second;
       
        if (ans[pos.first][pos.second] != 0) {
            pq.pop();
            continue;
        }
        pq.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (map[nx][ny] == now) continue;

            if (map[nx][ny] > now) {
                ans[pos.first][pos.second] += ans[nx][ny];
            }
            else {
                pq.push({map[nx][ny], {nx, ny}});
            }
        }
    }

    cout << ans[m-1][n-1] << '\n';
    return 0;
}