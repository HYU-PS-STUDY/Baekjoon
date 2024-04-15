#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define PLANE_MAX 11
using namespace std;
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int N,M,K;

// NOTE : 매 겨울 채워지는 양분의 양
int plane[PLANE_MAX][PLANE_MAX];

// NOTE : 각 칸의 양분 상태
int nutrient[PLANE_MAX][PLANE_MAX];

/**
 * NOTE
 * - 각 칸에는 여러 개의 나무가 담길 수 있다
 * - 나무의 나이가 담기게 된다
*/
vector<int> tree[PLANE_MAX][PLANE_MAX];

bool age_cmp(int a1, int a2) {
    return a1 < a2;
}

bool check_bound(int y, int x) {
    return y>=1 && y<=N && x>=1 && x<=N;
}

void spring_and_summer() {
    // spring
    for (int y=1; y<=N; ++y) {
        for (int x=1; x<=N; ++x) {
            if (tree[y][x].empty()) continue;

            // NOTE : 가장 어린 나무가 먼저 양분을 먹는다
            sort(tree[y][x].begin(), tree[y][x].end(), age_cmp);

            // NOTE : 양분을 섭취하고 나이가 먹은 나무들의 나이가 담긴다
            vector<int> tmp;

            int die = 0;

            for (int i=0; i<tree[y][x].size(); ++i) {
                int age = tree[y][x][i];

                if (nutrient[y][x] < age) {
                    die += age/2;
                }
                else {
                    nutrient[y][x] -= age;
                    tmp.push_back(age+1);
                }
            }

            tree[y][x].clear();
            for (const auto& n : tmp) {
                tree[y][x].push_back(n);
            }

            // summer
            nutrient[y][x] += die;
        }
    }
}

void fall() {
    for (int y=1; y<=N; ++y) {
        for (int x=1; x<=N; ++x) {
            if (tree[y][x].empty()) continue;

            for (int t=0; t<tree[y][x].size(); ++t) {
                // NOTE : 나이가 5의 배수여야 번식 가능하다
                if (tree[y][x][t]%5 != 0) continue;

                for (int i=0; i<8; ++i) {
                    int ny=y+dy[i], nx=x+dx[i];
                    if (!check_bound(ny, nx)) continue;
                    tree[ny][nx].push_back(1);
                }
            }
        }
    }
}

void winter() {
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) {
            nutrient[i][j] += plane[i][j];
        }
    }
}

int answer() {
    int cnt = 0;
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) {
            if (tree[i][j].empty()) continue;
            cnt += tree[i][j].size();
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N >> M >> K;
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) {
            cin >> plane[i][j];
            nutrient[i][j] = 5;
        }
    }

    int y,x,age;
    for (int i=0; i<M; ++i) {
        cin >> y >> x >> age;
        tree[y][x].push_back(age);
    }

    while (K--) {
        spring_and_summer();
        fall();
        winter();
    }
    cout << answer();
    return 0;
}