#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int r, c, n;
char map[202][202];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void print_map() {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << map[i][j];
        }
        cout << '\n';
    }
}

void reverse_map() {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (map[i][j] == '.') map[i][j] =  'O';
            else map[i][j] =  '.';
        }
    }
}

void all_bomb() {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            map[i][j] = 'O';
        }
    }
}

void bomb() {
    vector<pii> v;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (map[i][j] == 'O') v.push_back({i, j});           
        }
    }
    for (pii p : v) {
        for (int i = 0; i < 4; ++i) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            map[nx][ny] = 'O';
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c >> n;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> map[i][j];
        }
    }
    if (n % 2 == 0) { // 짝수면 전부 폭탄
        all_bomb();
    }
    else if (n > 1 && n % 4 == 3) { // 폭탄 터지고 반대로 출력
        bomb();
        reverse_map();
    }
    else if (n > 1 && n % 4 == 1) {
        bomb();
        reverse_map();
        bomb();
        reverse_map();
    }
    print_map();
    
    return 0;
}