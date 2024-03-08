#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 20001
#define INF 9999999
int V, E, K;
struct info {
    int idx; int w;
};
// NOTE : 비용이 작은 것부터 처리하기 위해 우선순위 큐에 사용되는 comparator
struct cmp {
    bool operator()(const info& a, const info& b) {
        return a.w > b.w;
    }
};
vector<info> map[MAX];
int dist[MAX];

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> V >> E >> K;
    int u,v,w;
    for (int i=0; i<E; ++i) {
        cin >> u >> v >> w;
        map[u].push_back({v, w});
    }

    // NOTE : 각 도시에 도달하는 비용을 INF로 초기화
    for (int i=1; i<=V; ++i) dist[i] = INF;
    
    priority_queue<info, vector<info>, cmp> min_pq;
    min_pq.push({K, 0});

    // NOTE : 시작 도시 K의 비용은 0으로 초기화
    dist[K] = 0;

    while (!min_pq.empty()) {
        auto p = min_pq.top(); min_pq.pop();
        int cur = p.idx, w = p.w;

        // NOTE : 해당 도시에 도달하는 비용이 w보다 이미 더 작다면 스킵한다
        if (dist[cur] < w) continue;

        for (int i=0; i<map[cur].size(); ++i) {
            int next = map[cur][i].idx, nw = map[cur][i].w;

            // NOTE : 다익스르라 알고리즘에 따라서 갱신
            if (dist[next] > w + nw) {
                dist[next] = w + nw;
                // NOTE : 우선순위 큐 덕분에 항상 dist가 작은 것부터 처리된다
                min_pq.push({next, dist[next]});
            }
        }
    }

    // NOTE : 각 dist를 조사해서 INF인지 아닌지만 판단하면 된다
    for (int i=1; i<=V; ++i) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }

    return 0;
}