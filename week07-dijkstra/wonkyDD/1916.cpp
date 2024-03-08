#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 1001
#define INF 99999999
struct info {
    int idx; int w;
};
// NOTE : 비용이 작은 것부터 처리하기 위해 우선순위 큐에 사용되는 comparator
struct cmp {
    bool operator()(const info& a, const info& b) {
        return a.w > b.w;
    }
};
int N,M;
vector<info> map[MAX];
int dist[MAX];

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int u,v,w; int start, dest;
    cin >> N >> M;
    for (int i=0; i<M; ++i) {
        cin >> u >> v >> w;
        map[u].push_back({v, w});
    }
    cin >> start >> dest;

    // NOTE : 각 도시에 도달하는 비용을 INF로 초기화
    for (int i=1; i<=N; ++i) dist[i] = INF;
    priority_queue<info, vector<info>, cmp> pq;
    pq.push({start, 0});

    // NOTE : 시작 도시의 비용은 0으로 초기화
    dist[start] = 0;

    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int cur = p.idx, w = p.w;

        // NOTE : 해당 도시에 도달하는 비용이 w보다 이미 더 작다면 스킵한다
        if (dist[cur] < w) continue;

        for (int i=0; i<map[cur].size(); ++i) {
            int next = map[cur][i].idx, nw = map[cur][i].w;

            // NOTE : 다익스르라 알고리즘에 따라서 갱신
            if (dist[next] > nw+w) {
                dist[next] = nw+w;

                // NOTE : 우선순위 큐 덕분에 항상 dist가 작은 것부터 처리된다
                pq.push({next, dist[next]});
            }
        }
    }
    cout << dist[dest];
    return 0;
}
