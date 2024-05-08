#include <iostream>
using namespace std;
#define MAX 1001
int n,m;
int map[MAX][MAX];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m;

    char c;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            cin >> c;
            map[i][j] = c - '0';
        }
    }

    int ans = 0;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            if (map[i][j] == 0) continue;
            map[i][j] = min(map[i-1][j], min(map[i][j-1], map[i-1][j-1])) + 1;
            ans = max(ans , map[i][j]);
        }
    }
    cout << ans*ans;
    return 0;
}