#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100
using ll = long long;

int map[MAX][MAX];
ll dp[MAX][MAX];
int N;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> map[i][j];
        }
    }
    memset(dp, 0, sizeof(dp));

    /** NOTE : 시작점의 dp값을 1로 설정한다 */
    dp[0][0] = 1;
    for (int y=0; y<N; ++y) {
        for (int x=0; x<N; ++x) {
            /**
             * NOTE
             * - dp값이 갱신이 되지 않았다면 도달하지 못하는 경로이므로 패스한다
             * - 종착역이면 패스한다
            */
            if (dp[y][x] == 0 || (y == N-1 && x == N-1)) continue;

            int d = map[y][x];
            /** NOTE : 미래의 dp값을 누적 갱신 */
            if (y+d < N) dp[y+d][x] += dp[y][x];
            if (x+d < N) dp[y][x+d] += dp[y][x];
        }
    }

    cout << dp[N-1][N-1];
    return 0;
}