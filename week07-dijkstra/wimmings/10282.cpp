#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;
#define INF (1<<30)

int n, d, c;
int dist[10003];

void dijkstra(int start, vector<pair<int, int>> adj[]) {
    fill(dist, dist+10003, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dist[now] < cost) continue;
        
        for (pair<int, int> p : adj[now]) {
            int new_cost = p.first;
            int next = p.second;
            if (dist[next] > dist[now] + new_cost) {
                dist[next] = dist[now] + new_cost;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        vector<pair<int, int>> adj[10003];
        cin >> n >> d >> c;
        for (int i = 0; i < d; ++i) {
            int a, b, s; cin >> a >> b >> s;
            adj[b].push_back({s, a}); // 역방향으로 저장
        }
        dijkstra(c, adj); // 처음 해킹당한 컴퓨터부터 시작

        int maxi = -1;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] != INF) {
                cnt++;
                maxi = max(maxi, dist[i]); // 갈 수 있는 곳 중 가장 큰 수
            }
        }
        cout << cnt << " " << maxi << '\n';
    }    
    
    return 0;
}