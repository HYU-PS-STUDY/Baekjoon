#include <iostream>
using namespace std;
#define MAX 16
#define UPPER_BOUND 9999999
int w[MAX][MAX];
int dp[MAX][1 << MAX];
int N;

bool is_visited(int visited, int city) {
    return visited & (1 << city);
}

int make_visited(int visited, int city) {
    return visited | (1 << city);
}

int dfs(int cur, int visited) {
    if (visited == (1 << N) - 1) {
        if (w[cur][0] == 0) return UPPER_BOUND;
        return w[cur][0];
    }

    if (dp[cur][visited] != 0) return dp[cur][visited];

    dp[cur][visited] = UPPER_BOUND;
    for (int next=0; next<N; ++next) {
        if (is_visited(visited, next) || w[cur][next] == 0) continue;
        dp[cur][visited] = min(dp[cur][visited], w[cur][next] + dfs(next, make_visited(visited, next)));
    }
    return dp[cur][visited];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> w[i][j];
        }
    }
    cout << dfs(0, 1 << 0);
    return 0;
}
