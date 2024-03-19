#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int ans;
/* 
    dp[i][j] : 숫자 길이가 i, 일의 자리 숫자가 j일 때 계단수의 개수
    길이가 i-1인 숫자 중 일의 자리가 j+1 인 경우
    +
    길이가 i-1인 숫자 중 일의 자리가 j-1 인 경우
 */
int dp[102][10]; 
int mod = 1000000000;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for (int i = 1; i <= 9; ++i) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (j+1 <= 9) {
                dp[i][j] = (dp[i][j]%mod + dp[i-1][j+1]%mod)%mod;
            }
            if (j-1 >= 0) {
                dp[i][j] = (dp[i][j]%mod + dp[i-1][j-1]%mod)%mod;
            }
        }
    }
    for (int i = 0; i <= 9; ++i) {
        ans = (ans%mod + dp[n][i]%mod)%mod;
    }
    cout << ans << '\n';

    return 0;
}