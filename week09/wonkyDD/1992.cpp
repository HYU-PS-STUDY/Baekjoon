#include <iostream>
#include <string>
using namespace std;
#define MAX 64
int N;
char map[MAX][MAX];

void dfs(int y, int x, int len) {
    // NOTE : 길이가 1이면 압축 불가능
    if (len == 1) {
        cout << map[y][x];
        return;
    }

    bool flag = true;
    char c = map[y][x];
    // NOTE : 모든 dfs 깊이마다 압축 가능한지 여부를 판단한다
    for (int i=y; i<y+len; ++i) {
        for (int j=x; j<x+len; ++j) {
            if (c != map[i][j]) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }

    // NOTE : 압축 가능했다면...
    if (flag) {
        cout << c;
        return;
    }

    // NOTE : 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래 순서
    cout << "(";
    dfs(y, x, len/2);
    dfs(y, x+len/2, len/2);
    dfs(y+len/2, x, len/2);
    dfs(y+len/2, x+len/2, len/2);
    cout << ")";
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> map[i][j];
        }
    }

    dfs(0, 0, N);
    return 0;
}