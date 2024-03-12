#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

#define MAX 10
struct pos {
    int y; int x;
};
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int N, M;
char board[MAX][MAX];
int ans = INT_MAX;

int count(int cy, int ncy, int cx, int ncx) {
    return abs(cy-ncy) + abs(cx-ncx);
}

int inverse(int dir) {
    int inv;
    switch (dir)
    {
    case 0:
        inv = 1;
        break;
    case 1:
        inv = 0;
        break;
    case 2:
        inv = 3;
        break;
    case 3:
        inv = 2;
        break;
    }
    return inv;
}

void dfs(pos red, pos blue, int cnt, int dir) {
    if (cnt > 10 || cnt >= ans) return;

    // NOTE : 빨간 구슬이 탈출하는지 확인한다
    int nry = red.y, nrx = red.x;
    bool red_out = false;
    while (1) {
        nry += dy[dir]; nrx += dx[dir];
        if (board[nry][nrx] == '#') break;
        if (board[nry][nrx] == 'O') {
            red_out = true;
            break;
        }
    }
    // NOTE : # or O => . 위치로 한칸 보정
    nry -= dy[dir]; nrx -= dx[dir];

    // NOTE : 파란 구슬이 탈출하는지 확인한다
    int nby = blue.y, nbx = blue.x;
    while (1) {
        nby += dy[dir]; nbx += dx[dir];
        if (board[nby][nbx] == '#') break;
        // NOTE : 파란 구슬이 탈출 했다면 바로 탐색을 종료한다
        if (board[nby][nbx] == 'O') {
            return;
        }
    }
    // NOTE : # or O => . 위치로 한칸 보정
    nby -= dy[dir]; nbx -= dx[dir];

    // NOTE : 빨간 구슬이 탈출했다면 ans를 갱신한다
    if (red_out) {
        ans = min(ans, cnt);
        return;
    }

    /**
     * NOTE
     * - 빨간 / 파란 구슬은 같은 칸에 존재할 수 없다
     * - 하지만 빨/파 구슬에 대해 각각 while을 돌리고 있으므로 값이 같아지는 상황이 나오게 된다
     * - 따라서 값이 같았을 경우 이동한 거리가 큰 쪽을 한칸 보정해준다
    */
    if ((nry == nby) && (nrx == nbx)) {
        int rd = count(red.y, nry, red.x, nrx);
        int bd = count(blue.y, nby, blue.x, nbx);

        // NOTE : 기울였을 때 더 많이 움직였다면 한칸 되돌려 줘야 한다
        if (rd > bd) { nry -= dy[dir]; nrx -= dx[dir]; }
        else { nby -= dy[dir]; nbx -= dx[dir]; }
    }

    for (int i=0; i<4; ++i) {
        // NOTE : 이전 뱡향과 똑같은 방향 or 반대방향 (되돌아가는) 은 의미가 없다
        if (i == dir || i == inverse(dir)) continue;

        pos nr = {nry, nrx}, nb = {nby, nbx};
        dfs(nr, nb, cnt+1, i);
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N >> M;
    pos r,b;

    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'R') r = {i, j};
            else if (board[i][j] == 'B') b = {i, j};
        }
    }

    for (int i=0; i<4; ++i) {
        dfs(r, b, 1, i);
    }

    if (ans == INT_MAX || ans > 10) ans = -1;
    cout << ans;
    return 0;
}