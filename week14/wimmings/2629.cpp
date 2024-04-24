#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
int n;
int w[32];

int m;
bool dp[32][16];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];        
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 15; ++j) {
            if (!dp[i - 1][j]) continue;
            dp[i][j] = 1;

            dp[i][abs(j - w[i])] = 1;
            if (j + w[i] <= 40000) dp[i][j + w[i]] = 1;
        }
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int mar; cin >> mar;
        if (dp[n][mar]) cout << "Y ";
        else cout << "N ";
    }
    cout << '\n';
    return 0;
}