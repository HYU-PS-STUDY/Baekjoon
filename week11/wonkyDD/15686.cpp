#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define MAX 13
using pii = pair<int, int>;
struct pos {
    int y; int x;
};
vector<pos> home, chicken;
vector<pos> choose;

bool check[MAX];

int N,M;
int ans = INT_MAX;

int dist(const pos& p1, const pos& p2) {
    return abs(p1.y - p2.y) + abs(p1.x - p2.x);
}

int cal() {
    int sum = 0;
    for (int i=0; i<home.size(); ++i) {
        int tmp = INT_MAX;
        for (int j=0; j<choose.size(); ++j) {
            tmp = min(tmp, dist(home[i], choose[j]));
        }
        sum += tmp;
    }
    return sum;
}

void dfs(int cur, int cnt) {
    if (cnt == M) {
        ans = min(ans, cal());
        return;
    }

    for (int i=cur; i<chicken.size(); ++i) {
        if (check[i]) continue;
        choose.push_back(chicken[i]); check[i] = true;
        dfs(i, cnt+1);
        choose.pop_back(); check[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            int t; cin >> t;
            if (t == 1) home.push_back({i, j});
            else if (t == 2) chicken.push_back({i, j});
        }
    }
    dfs(0, 0);
    cout << ans;
    return 0;
}