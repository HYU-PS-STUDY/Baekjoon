#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;
#define INF (1<<30)

int n, d;
int dist[10003];

vector<pair<int, int>> adj[10003];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        int a, b, c; cin >> a >> b >> c;
        adj[b].push_back({a, c});
    }

    for (int i = 1; i <= d; ++i) {
        dist[i] = i;
    }

    for (int i = 1; i <= d; ++i) {
        int tmp = INF;
        for (pair<int, int> p : adj[i]) {
            int start = p.first;
            int cost = p.second;
            tmp = min(tmp, dist[start] + cost);
        }
        dist[i] = min(dist[i-1]+1, tmp);
    }

    cout << dist[d] << '\n';
    return 0;
}