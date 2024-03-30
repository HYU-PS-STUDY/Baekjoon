#include <iostream>
#include <cstring>
#define MAX 100001
using namespace std;
int choice[MAX];
bool visited[MAX];
bool cycle[MAX];
int n;
int cnt;

void dfs(int cur) {
    visited[cur] = true;
    int next = choice[cur];
    if (visited[next]) {
        // NOTE : 방문이 됐음에도 cycle로 마킹되지 않았어야만 사이클로 카운팅한다
        if (!cycle[next]) {
            for (int i=next; i!=cur; i=choice[i]) ++cnt;
            ++cnt;
        }
    }
    else dfs(next);

    /**
     * NOTE
     * - 선택한 학생에 대한 dfs를 끝내고 나서야 cycle 마킹
     * - 위에있는 cnt를 세는 부분에서 flag로 사용된다
    */
    cycle[cur] = true;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        cin >> n;
        cnt = 0;

        for (int i=1; i<=n; ++i) {
            cin >> choice[i];
            visited[i] = cycle[i] = false;
        }

        for (int i=1; i<=n; ++i) {
            if (!visited[i]) dfs(i);
        } 
        cout << n-cnt << '\n';
    }
    return 0;
}