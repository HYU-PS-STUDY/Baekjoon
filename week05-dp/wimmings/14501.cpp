#include <iostream>
#include <vector>
#include <cstring>
#include <memory.h>
#include <algorithm>
#include <queue>

using namespace std;

int finish[17];
int pay[17];
int dp[17];

int n;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int time, p; cin >> time >> p;
        pay[i] = p;             // 받는 돈
        finish[i] = i + time;   // 끝나는 날
    }

    int maxi = 0;
    for (int i = 1; i <= n; ++i) {
        int end = finish[i];
        if (dp[i] < maxi) dp[i] = maxi;
        dp[end] = max(dp[end], dp[i] + pay[i]);
        maxi = max(maxi, dp[i]);
    }
    cout << *max_element(dp, dp + 2 + n) << '\n';

    return 0;
}