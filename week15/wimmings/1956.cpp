#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>

#define INF 1000000000 

using namespace std;

int dist[402][402];

int V, E;

void floyd() {
    for (int k = 1; k <= V; ++k) {
        for (int i = 1; i <= V; ++i) {
            for (int j = 1; j <= V; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for (int i = 0; i < E; ++i) {
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = c;
    }
    floyd();
    
    // bool cycle = false;
    int ans = INF;
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (i == j) continue;
            if (dist[i][j] != INF && dist[j][i] != INF) {
                // 둘 다 INF가 아닐 때 둘을 더한 게 사이클 거리 -> 여러 군데 방문하는 사이클도 다 계산된 거리다
                int sum = dist[i][j] + dist[j][i];
                ans = min(ans, sum);
                // cycle = true;
            }        
        }
    }
    if (ans != INF) cout << ans << '\n';
    else cout << "-1" << '\n';
    return 0;
}