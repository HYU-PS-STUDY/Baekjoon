#include <iostream>
using namespace std;
#define MAX 1001
int N;
int dp[MAX][3];
#define MAX 1001
typedef enum {
    RED,
    GREEN,
    BLUE
} Color;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N;
    int r,g,b;
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i=1; i<=N; ++i) {
        cin >> r >> g >> b;
        dp[i][RED] = min(dp[i-1][GREEN], dp[i-1][BLUE]) + r;
        dp[i][GREEN] = min(dp[i-1][RED], dp[i-1][BLUE]) + g;
        dp[i][BLUE] = min(dp[i-1][RED], dp[i-1][GREEN]) + b;
    }
    cout << min(dp[N][RED], min(dp[N][GREEN], dp[N][BLUE]));
    return 0;
}
