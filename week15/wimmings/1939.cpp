#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> adj[10002]; // 도착지, 중량제한
int src, dest;
bool visited[10002];

bool solve(int mid) {
    // bfs 돌면서 특정 무게로 도착지에 도착할 수 있는지
    memset(visited, false, sizeof(visited));
    queue<int> q;

    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == dest) {
            // 도착 가능
            return true;
        }
        for (int i = 0; i < adj[now].size(); ++i) {
            int next = adj[now][i].first;
            int w = adj[now][i].second;

            if (visited[next]) continue;
            if (w >= mid) {
                // 건널 수 있다면 넣기
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int maxi = -1;
    for (int i = 0; i < m; ++i) {
        int a, b;
        int c; cin >> a >> b >> c;
        maxi = max(maxi, c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    cin >> src >> dest;

    int st = 1;
    int en = maxi;

    int ans;
    while (st <= en) {
        int mid = (st+en)/2;
        if (solve(mid)) {
            ans = mid;
            st = mid + 1;
        }
        else en = mid - 1;
    }
    cout << ans << '\n';


    return 0;
}