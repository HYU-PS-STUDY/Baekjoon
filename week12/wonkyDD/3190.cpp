#include <iostream>
#include <unordered_map>
#include <deque>
using namespace std;
#define BOARD_MAX 101

struct snake {
    int y; int x;
};

// NOTE : Up, Down, Left, Right 순서
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int N,K,L;
unordered_map<int, char> time_to_dir;
bool apple[BOARD_MAX][BOARD_MAX];

// NOTE : front: 꼬리, back: 머리
deque<snake> dq;
// NOTE : 뱀은 처음에 오른쪽을 향한다.
int dir=3;
bool game_over;

int dir_converter(char c) {
    if (c == 'L') {
        if (dir == 0) return 2;
        if (dir == 1) return 3;
        if (dir == 2) return 1;
        if (dir == 3) return 0;
    }

    if (c == 'D') {
        if (dir == 0) return 3;
        if (dir == 1) return 2;
        if (dir == 2) return 0;
        if (dir == 3) return 1;
    }

    return -1;
}

bool check_bound(int y, int x) {
    return y>=1 && y<=N && x>=1 && x<=N;
}

bool check_itself(int y, int x) {
    for (const auto& p : dq) {
        if (p.y == y && p.x == x) return false;
    }
    return true;
}

void rotate(int time) {
    char l_or_d = time_to_dir[time];
    dir = dir_converter(l_or_d);
}

void move() {
    // NOTE : dq.back == 머리, dq.front == 꼬리
    int ny = dq.back().y+dy[dir], nx = dq.back().x+dx[dir];
    
    // NOTE : 만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다
    if (!check_bound(ny, nx) || !check_itself(ny, nx)) {
        game_over = true;
        return;
    }

    dq.push_back({ny, nx});

    // NOTE : 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다
    if (apple[ny][nx]) {
        apple[ny][nx] = false;
    }
    // NOTE : 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
    else {
        for (int i=0; i<dq.size()-1; ++i) {
            dq[i].y = dq[i+1].y;
            dq[i].x = dq[i+1].x;
        }
        dq.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N >> K;
    int r,c;
    for (int i=0; i<K; ++i) {
        cin >> r >> c;
        apple[r][c] = true;
    }
    cin >> L;
    int t; char d;
    for (int i=0; i<L; ++i) {
        cin >> t >> d;
        time_to_dir.insert({t, d});
    }

    int time = 0;
    dq.push_back({1, 1});
    while (1) {
        game_over = false;

        // NOTE : 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다
        move();
        ++time;

        if (game_over) break;

        // NOTE : 방향을 전환해야 하는 순간이면 전환한다
        if (time_to_dir.find(time) != time_to_dir.end()) rotate(time);
    }
    cout << time;
    return 0;
}