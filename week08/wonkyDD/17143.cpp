#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 101
struct shark {
    int id;
    int y; int x;
    int speed;
    int dir;
    int size;
    bool is_dead;
};
// NOTE : <dummy>, UP, DOWN, RIGHT, LEFT
int dy[] = {-9, -1, 1, 0, 0};
int dx[] = {-9, 0, 0, 1, -1};

int R,C,M;
vector<shark> sharks;
vector<int> map[MAX][MAX];
int fisher = 1;
int ans = 0;

bool is_over() {
    for (const auto& shark : sharks) {
        if (!shark.is_dead) return false;
    }
    return true;
}

void fish() {
    // NOTE : 낚시꾼은 지면과 가장 가까운 곳부터 낚시를 시작한다
    for (int i=1; i<=R; ++i) {
        // NOTE : shark id가 담겨있는 위치를 찾는다
        if (!map[i][fisher].empty()) {
            int shark_id = map[i][fisher][0]; 
            ans += sharks[shark_id].size;

            // NOTE : 포획했기 때문에 죽었다고 표기하고 해당 위치의 map은 비워준다
            sharks[shark_id].is_dead = true;
            map[i][fisher].clear();
            break;
        }
    }
}

int inverse_dir(int dir) {
    if (dir == 1) return 2;
    else if (dir == 2) return 1;
    else if (dir == 3) return 4;
    else return 3;
}

void move() {
    for (const auto& shark : sharks) {
        // NOTE : 포획된 상어는 고려하지 않는다
        if (shark.is_dead) continue;

        int y = shark.y, x = shark.x;

        // NOTE : 이제 이동할 것이기 때문에 기존 위치의 shark id 컨테이너는 비워준다
        map[y][x].clear();
    }

    for (auto& shark : sharks) {
        // NOTE : 죽은 상어는 이동시키지 않는다
        if (shark.is_dead) continue;

        int y = shark.y, x = shark.x, dir = shark.dir, speed = shark.speed;
        int ny = y, nx = x;

        // NOTE : 이동 방향이 UP or DOWN
        if (dir == 1 || dir == 2) {
            /**
             * NOTE
             * - 이동 방향이 위아래니까 R이 기준이다
             * - 기존 방향을 유지하며, 원래의 위치로 돌아오는데 걸리는 주기는 2 * (R-1)이다
            */
            int period = 2 * (R-1);
            if (speed >= period) speed %= period;

            for (int i=0; i<speed; ++i) {
                // NOTE : 일단 갱신을 하고, 위치 보정을 한다
                ny += dy[dir]; nx += dx[dir];
                if (ny < 1) {
                    ny += 2;
                    dir = inverse_dir(dir);
                }
                else if (ny > R) {
                    ny -= 2;
                    dir = inverse_dir(dir);
                }
            }
        }
        // NOTE : 이동 방향이 RIGHT or LEFT
        else {
            /**
             * NOTE
             * - 이동 방향이 위아래니까 C가 기준이다
             * - 기존 방향을 유지하며, 원래의 위치로 돌아오는데 걸리는 주기는 2 * (C-1)이다
            */
            int period = 2 * (C-1);
            if (speed >= period) speed %= period;

            for (int i=0; i<speed; ++i) {
                // NOTE : 일단 갱신을 하고, 위치 보정을 한다
                ny += dy[dir]; nx += dx[dir];
                if (nx < 1) {
                    nx += 2;
                    dir = inverse_dir(dir);
                }
                else if (nx > C) {
                    nx -= 2;
                    dir = inverse_dir(dir);
                }
            }
        }

        // NOTE : 새롭게 갱신한 좌표 자리에 shark id를 넣어준다
        shark.y = ny;
        shark.x = nx;
        shark.dir = dir;
        map[ny][nx].push_back(shark.id);
    }
}

// NOTE : size 기준으로 shark id를 내림 차순 정렬한다
bool cmp(int a, int b) {
    return sharks[a].size > sharks[b].size;
}

void eat() {
    for (int i=1; i<=R; ++i) {
        for (int j=1; j<=C; ++j) {
            if (map[i][j].size() > 1) {
                sort(map[i][j].begin(), map[i][j].end(), cmp);

                // NOTE : 가장 size가 큰 shark의 id
                int max_size_shark_id = map[i][j][0];

                // NOTE : 다른 상어들은 가장 큰 상어에게 모두 잡아먹힌다 (is_dead = true)
                for (int k=1; k<map[i][j].size(); ++k) {
                    int shark_id = map[i][j][k];
                    sharks[shark_id].is_dead = true;
                }

                // NOTE : 모두 비워주고 가장 size가 큰 상어만 남긴다
                map[i][j].clear();
                map[i][j].push_back(max_size_shark_id);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> R >> C >> M;
    int r,c,speed,dir,size;
    for (int i=0; i<M; ++i) {
        cin >> r >> c >> speed >> dir >> size;
        sharks.push_back({i, r, c, speed, dir, size, false});
        map[r][c].push_back(i);
    }

    for (; fisher<=C; ++fisher) {
        if (is_over()) break;
        fish();
        move();
        eat();
    }
    cout << ans;
    return 0;
}