#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 10
#define ISLAND_MAX 7

struct pos {
    int y; int x;
};

struct tbridge {
    int len; int start; int end;
};

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int N,M;
int map[MAX][MAX];
int island[MAX][MAX];
bool visited[MAX][MAX];
int island_cnt = 0;
vector<pos> land;
vector<tbridge> bridge;
int parent[ISLAND_MAX];

bool check_bound(int y, int x) {
    return y>=0 && y<N && x>=0 && x<M;
}

bool check(int y, int x) {
    return check_bound(y, x) && !visited[y][x] && map[y][x] == 1;
}

// NOTE : bfs를 하며 각 섬마다 id (island_cnt)를 부여한다
void numbering_island() {
    for (int i=0; i<land.size(); ++i) {
        int _y = land[i].y, _x = land[i].x;

        if (visited[_y][_x]) continue;

        queue<pos> q;
        visited[_y][_x] = true;
        island[_y][_x] = ++island_cnt;
        q.push({_y, _x});

        while (!q.empty()) {
            int y = q.front().y, x = q.front().x;
            q.pop();

            for (int i=0; i<4; ++i) {
                int ny=y+dy[i], nx=x+dx[i];
                if (!check(ny, nx)) continue;

                visited[ny][nx] = true;
                island[ny][nx] = island_cnt;

                q.push({ny, nx});
            }
        }
    }
}

void make_bridge() {
    // NOTE : 모든 땅 좌표를 순회하며 가능한 다리들을 모두 계산
    for (int i=0; i<land.size(); ++i) {
        int y=land[i].y, x=land[i].x;
        int start_island_id = island[y][x];

        for (int d=0; d<4; ++d) {
            int ny=y, nx=x;
            int len = 0;

            while (1) {
                ny += dy[d]; nx += dx[d];

                /**
                 * NOTE
                 * - 경계, 길이, 바다 위에 있는지 여부를 체크
                 * - 0은 바다, 1은 땅을 의미한다.
                */
                if (check_bound(ny, nx)) {
                    if (map[ny][nx] == 0) ++len;
                    else if (
                        map[ny][nx] == 1 &&
                        len>=2 &&
                        start_island_id != island[ny][nx]
                    ) {
                        bridge.push_back({len, start_island_id, island[ny][nx]});
                        break;
                    }
                    else break;
                }
                else break;
            }
        }
    }
}

int find(int a) {
    if (parent[a] == a) return a;
    return (parent[a] = find(parent[a]));
}

// NOTE : 다리 id 값이 작은 쪽을 부모로
void uni(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa == pb) return;

    if (pa < pb) parent[pb] = pa;
    else parent[pa] = pb;
}

bool has_same_parent(int a, int b) {
    return find(a) == find(b);
}

bool b_cmp(tbridge& a, tbridge& b) { return a.len < b.len; }

int answer() {
    // NOTE : 다리 길이 최소합을 얻어야 한다
    sort(bridge.begin(), bridge.end(), b_cmp);

    for (int i=1; i<=island_cnt; ++i) {
        parent[i] = i;
    }

    int total_len = 0;
    for (int i=0; i<bridge.size(); ++i) {
        // NOTE : 연결되어 있지 않은 섬들에 대해 union 연산을 진행
        if (!has_same_parent(bridge[i].start, bridge[i].end)) {
            uni(bridge[i].start, bridge[i].end);
            total_len += bridge[i].len;
        }
    }

    // NOTE : 다리 id 값이 작은 쪽을 부모로 뒀기 때문에 1이 아니면 연결될 수 없음을 뜻함
    for (int i=1; i<=island_cnt; ++i) {
        if (find(i) != 1) {
            return -1;
        }
    }

    return total_len;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N >> M;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            // NOTE : 0은 바다, 1은 땅을 의미한다.
            cin >> map[i][j];
            if (map[i][j] == 1) {
                // NOTE : bridge 후보군들을 만들기위해 완탐하기 때문에 땅들의 좌표를 미리 확보
                land.push_back({i, j});
            }
        }
    }

    numbering_island();
    make_bridge();
    cout << answer();

    return 0;
}