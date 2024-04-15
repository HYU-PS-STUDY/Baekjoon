#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

int T, N, K, W, last;

ll delay[1002]; 
ll dp[1002];    

int in[1002];
vector<int> order[1002];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        memset(delay, 0, sizeof(delay));
        memset(dp, 0, sizeof(dp));
        memset(in, 0, sizeof(in));
        memset(order, 0, sizeof(order));
        cin >> N >> K;
        for (int i = 1; i <= N; ++i) {
            cin >> delay[i];
            dp[i] = delay[i];
        }
        for (int i = 0; i < K; ++i) {
            int first, second; cin >> first >> second;
            order[first].push_back(second);
            in[second]++;                   // second로 들어오는 선 개수 증가
        }
        cin >> last;
       
        // in이 0인 거 골라서 쭉 돌기
        queue<int> q;
        for (int i = 1; i <= N; ++i) {
            if (in[i] == 0) q.push(i); // 젤 끝에 있는 거, 젤 처음해야하는 건물
        }
        while (!q.empty()) {
            int start = q.front();
            q.pop();
            for (int i = 0; i < order[start].size(); ++i) { // start에서 갈 수 있는 점에다가 더함, 도착지의 in을 빼주고, 만약 0되면 큐에 넣어주기
                int next = order[start][i];
                if (dp[next] < dp[start] + delay[next]) {
                    dp[next] = dp[start] + delay[next];
                }
                in[next]--;
                if (in[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        cout << dp[last] << '\n'; // last까지 짓는 데 걸리는 시간
    }
    return 0;
}