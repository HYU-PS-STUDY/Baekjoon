#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 50
#define MAX_VIRUS 2500

struct pos {
    int y; int x;
};

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
vector<pos> virus;
vector<pos> activated;
bool visited[MAX_VIRUS];

int N,M;
int lab[MAX][MAX];
int time_map[MAX][MAX];
int ans = INT_MAX;

int empty_cnt = 0;
int infect_cnt = 0;

bool check(int y, int x) {
    return y>=0 && y<N && x>=0 && x<N && (lab[y][x] != 1) && (time_map[y][x] == -1);
}

int bfs() {
    infect_cnt = 0;

    /**
     * NOTE
     * -1로 처음에 갱신하여 바이러스가 확산되지 않았음을 표기
    */
    memset(time_map, -1, sizeof(time_map));

    queue<pos> q;
    for (const auto& p : activated) {
        q.push(p);
        time_map[p.y][p.x] = 0;
    }

    int time = 0;
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int y = p.y, x = p.x;

        for (int i=0; i<4; ++i) {
            int ny=y+dy[i], nx=x+dx[i];

            if (!check(ny, nx)) continue;

            time_map[ny][nx] = time_map[y][x] + 1;

            /**
             * NOTE
             * - 빈땅이었을 때에만 bfs가 리턴하는 time을 갱신한다
             * - 이미 바이러스가 있는 칸 (2) 일 경우에는 시간이 소요되지 않는다
            */
            if (lab[ny][nx] == 0) {
                ++infect_cnt;
                time = time_map[ny][nx];
            }

            q.push({ny, nx});
        }
    }
    return time;
}

void dfs(int x, int cnt) {
    if (cnt == M) {
        int t = bfs();

        // NOTE : 모든 빈 칸에 확산되지 않았다면 최소 시간 갱신 x
        if (empty_cnt == infect_cnt) ans = min(t, ans);
        return;
    }

    for (int i=x; i<virus.size(); ++i) {
        if (visited[i]) continue;
        visited[i] = true; activated.push_back(virus[i]);
        dfs(i, cnt+1);
        visited[i] = false; activated.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> lab[i][j];

            // NOTE : virus 위치를 미리 저장해 놓는다
            if (lab[i][j] == 2) virus.push_back({i, j});

            // NOTE : 모든 빈칸에 확산되었는지 확인하기 위해 빈칸의 개수를 세놓는다
            else if (lab[i][j] == 0) ++empty_cnt;
        }
    }

    dfs(0, 0);
    if (ans == INT_MAX) ans = -1;
    cout << ans;
    return 0;
}