#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;
int n, m;
int map[9][9];
int tmp_map[9][9];

/*        -> 3
          (-1,0)
 2 <-(0,-1)(0,0)(0,1) -> 0
          (1,0)
          -> 1

    cctv1 : 0, 1, 2, 3
    cctv2 : 0-2, 1-3                    (2차이 2개)
    cctv3 : 0-1, 1-2, 2-3, 3-0          (1차이 2개)
    cctv4 : 3-0-1, 0-1-2, 1-2-3, 2-3-0  (1차이 3개)
    cctv5 : 0-1-2-3                     (1차이 4개)
 */

int dx[4] = {0, 1, 0, -1}; 
int dy[4] = {1, 0, -1, 0};

vector<pair<int, int>> v;

void watch(int x, int y, int way) {
    way %= 4;

    for (; ; ) {
        x += dx[way];
        y += dy[way];

        if (x < 0 || y < 0 || x >= n || y >= m) return;
        if (tmp_map[x][y] == 6) return;
        if (tmp_map[x][y] == 0) { // 0일 때만 체크하도록, 다른 cctv는 건너뜀
            tmp_map[x][y] = -1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
            if (1 <= map[i][j] && map[i][j] <= 5) {
                v.push_back({i, j});
            }
        }
    }
    int mini = 100;
    int cnt = v.size();         // cctv 개수
    int total = (1 << (2*cnt)); // 방향 돌 수 있는 총 경우의 수 (4^cnt)
    
    for (int i = 0; i < total; ++i) {
        copy(&map[0][0], &map[0][0]+81, &tmp_map[0][0]); // 임시 배열에 저장
        int total_tmp = i;

        for (int j = 0; j < cnt; ++j) { // cctv 개수마다 다 돌기
            int way = total_tmp % 4;
            total_tmp /= 4;

            int x = v[j].first;
            int y = v[j].second;
            if (map[x][y] == 1) {
                watch(x, y, way);
            }
            else if (map[x][y] == 2) {
                watch(x, y, way);
                watch(x, y, way + 2);
            }
            else if (map[x][y] == 3) {
                watch(x, y, way);
                watch(x, y, way+1);
            }
            else if (map[x][y] == 4) {
                watch(x, y, way);
                watch(x, y, way+1);
                watch(x, y, way+2);
            }
            else if (map[x][y] == 5) {
                watch(x, y, way);
                watch(x, y, way+1);
                watch(x, y, way+2);
                watch(x, y, way+3);
            }
        }
        // 모든 방법의 방향마다 모든 cctv 탐색 후 사각지대 수 계산
        int res = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (tmp_map[r][c] == 0) res++;
            }
        }
        mini = min(mini, res);
    }
    cout << mini << '\n';

    return 0;
}