#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;
int n, m, h;

bool ladder[32][12];
int ans = 5;

bool isSuccess() {
    for (int j = 1; j <= n; ++j) {
        int original_j = j;
        
        for (int i = 1; i <= h; ++i) {
            if (ladder[i][j]) {
                j++;
            }
            else if (ladder[i][j-1]) {
                j--;
            }
        }       
        if (j != original_j) return false;
    }
    return true;
}

void dfs(int cnt, int H) {
    if (cnt > 3) return;
    // 만약 조작 성공 -> cnt 최솟값 갱신
    if (isSuccess()) {
        ans = min(ans, cnt);
        return;
    }

    for (int i = H; i <= h; ++i) {
        for (int j = 1; j < n; ++j) {
            if (ladder[i][j] || ladder[i][j-1] || ladder[i][j+1]) continue; // 자기 자신과 양 옆을 봤을 때 사다리가 하나라도 있으면 패스
            ladder[i][j] = 1;
            dfs(cnt+1, i);
            ladder[i][j] = 0;
        }
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> h;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; // b, b+1 세로선, a위치에서 연결
        ladder[a][b] = 1;
    }
    dfs(0, 1);
    
    if (ans == 5) ans = -1;
    cout << ans << '\n';

    return 0;
}