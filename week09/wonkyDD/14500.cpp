#include <iostream>
using namespace std;
#define MAX 500
int N,M;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int ans = 0;

bool check(int y, int x) {
    return y>=0 && y<N && x>=0 && x<M;
}

void dfs(int y, int x, int cnt, int cur) {
    if (cnt == 4) {
        ans = max(ans, cur);
        return;
    }

    for (int i=0; i<4; ++i) {
        int ny = y+dy[i], nx = x+dx[i];
        if (!check(ny, nx) || visited[ny][nx]) continue;

        visited[ny][nx] = true;
        dfs(ny, nx, cnt+1, cur+map[ny][nx]);
        visited[ny][nx] = false;
    }
}

void ooh(int y, int x) {
    int sum = map[y][x];
    int cnt = 0;
    int tmp = 1001;
    for (int i=0; i<4; ++i) {
        int ny = y+dy[i], nx = x+dx[i];
        if (!check(ny, nx)) continue;
        ++cnt;
        sum += map[ny][nx];
        tmp = min(tmp, map[ny][nx]);
    }

    if (cnt < 3) return;
    if (cnt == 3) {
        ans = max(ans, sum);
        return;
    }

    // cnt == 4
    ans = max(ans, sum - tmp);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> map[i][j];
        }
    }

    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            visited[i][j] = true;
            dfs(i, j, 1, map[i][j]);
            visited[i][j] = false;
            // ㅜ
            ooh(i, j);
        }
    }
    cout << ans;
    return 0;
}