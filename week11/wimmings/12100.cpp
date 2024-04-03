#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;
int n;

int map[22][22];
bool combined[22][22];

int maxi = -1;
void up() {
    memset(combined, 0, sizeof(combined));
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) { 
            if (map[i][j] == 0) continue;

            // i와 가까운 행부터 위로 올라가면서 두 행씩 살피자      
            for (int k = i-1; k >= 0; --k) {
                // [k][j] : 합침을 당할 [k+1][j] : 합치러 갈
                if (!combined[k][j] && map[k+1][j] == map[k][j]) { 
                    map[k][j] *= 2;
                
                    combined[k][j] = 1;
                    map[k+1][j] = 0;
                    break; // 합쳐진 경우 break해서 다음 행 넘어가도 됨. (어차피 예전에 다 땡겨 놓은 상태)
                }
                else if (map[k][j] == 0) {
                    // 그냥 한 칸 이동한 경우는 앞에 가서 합쳐질 수도 있고, 그냥 더 이동할 수 있기에
                    // break 없이 앞을 더 살펴봐야함
                    map[k][j] = map[k+1][j];
                    map[k+1][j] = 0;
                }
                else break; // 이동할 수 없는 경우도 break해서 다음 행 넘어가도 됨.
            }
        }
    }
}

void down() {
    memset(combined, 0, sizeof(combined));
    for (int i = n-2; i >= 0; --i) { 
        for (int j = 0; j < n; ++j) { 
            if (map[i][j] == 0) continue;
            for (int k = i+1; k < n; ++k) {       
                if (!combined[k][j] && map[k-1][j] == map[k][j]) {
                    map[k][j] *= 2;
                
                    combined[k][j] = 1;
                    map[k-1][j] = 0;
                    break;
                }
                else if (map[k][j] == 0) {
                    map[k][j] = map[k-1][j];
                    map[k-1][j] = 0;
                }
                else break;
            }
        }
    }
}

void right() {
    memset(combined, 0, sizeof(combined));
    for (int j = n-2; j >= 0; --j) { 
        for (int i = 0; i < n; ++i) { 
            if (map[i][j] == 0) continue;
            for (int k = j+1; k < n; ++k) {       
                if (!combined[i][k] && map[i][k-1] == map[i][k]) {
                    map[i][k] *= 2;
                
                    combined[i][k] = 1;
                    map[i][k-1] = 0;
                    break;
                }
                else if (map[i][k] == 0) {
                    map[i][k] = map[i][k-1];
                    map[i][k-1] = 0;
                }
                else break;
            }
        }
    }

}
void left() {
    memset(combined, 0, sizeof(combined));
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n; ++i) { 
            if (map[i][j] == 0) continue;
            for (int k = j-1; k >= 0; --k) {       
                if (!combined[i][k] && map[i][k+1] == map[i][k]) {
                    map[i][k] *= 2;
                
                    combined[i][k] = 1;
                    map[i][k+1] = 0;
                    break;
                }
                else if (map[i][k] == 0) {
                    map[i][k] = map[i][k+1];
                    map[i][k+1] = 0;
                }
                else break;
            }
        }
    }

}
void move2048(int dir) {
    if (dir == 0) up();
    else if (dir == 1) down();
    else if (dir == 2) right();
    else left();
}
void get_max() {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (map[r][c] > maxi) {
                maxi = map[r][c];
            }
        }
    }
}
void dfs(int step) {
    if (step == 5) {
        return;
    }
    int tmp_map[22][22];
    copy(&map[0][0], &map[0][0]+484, &tmp_map[0][0]); // 임시 배열에 두었다가

    for (int i = 0; i < 4; ++i) {
        move2048(i); // 4가지 방향에 따라 움직이기
        get_max();   // 최댓값 구하기
        
        dfs(step+1);
        copy(&tmp_map[0][0], &tmp_map[0][0]+484, &map[0][0]); // 다시 돌려놓기
    }
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
        }
    }
    dfs(0);
    cout << maxi << '\n';

    return 0;
}