#include <iostream>
#include <string>
using namespace std;
#define MAX 20

int N,M,sy,sx,K;
int map[MAX][MAX];
// NOTE : 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4로 주어진다.
int dy[] = {0, 0, 0, -1, 1};
int dx[] = {0, 1, -1, 0, 0};
int dice[7];

bool check(int y, int x) {
    return y>=0 && y<N && x>=0 && x<M;
}

void move(int dir) {
    int d1=dice[1], d2=dice[2], d3=dice[3], d4=dice[4], d5=dice[5], d6=dice[6];

    // 동
    if (dir == 1) {
        dice[1] = d4; dice[3] = d1; dice[6] = d3; dice[4] = d6;
        return;
    }

    // 서
    if (dir == 2) {
        dice[1] = d3; dice[3] = d6; dice[6] = d4; dice[4] = d1;
        return;
    }

    // 북
    if (dir == 3) {
        dice[1] = d5; dice[2] = d1; dice[6] = d2; dice[5] = d6;
        return;
    }

    // 남 (dir == 4)
    dice[1] = d2; dice[2] = d6; dice[6] = d5; dice[5] = d1;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N >> M >> sy >> sx >> K;

    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> map[i][j];
        }
    }

    int dir;
    int y=sy, x=sx;

    // NOTE : K번에 걸쳐서 주사위를 굴린다
    while (K--) {
        cin >> dir;
        int ny=y+dy[dir], nx=x+dx[dir];

        // NOTE : 만약 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시해야 한다
        if (!check(ny, nx)) continue;

        move(dir);

        // NOTE : 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다.
        if (map[ny][nx] == 0) map[ny][nx] = dice[6];
        // NOTE : 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
        else {
            dice[6] = map[ny][nx];
            map[ny][nx] = 0;
        }

        // NOTE : 주사위를 굴리고 윗면을 출력
        cout << dice[1] << '\n';
        y = ny; x = nx;
    }
    return 0;
}