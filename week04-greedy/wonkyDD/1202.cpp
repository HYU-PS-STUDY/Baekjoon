#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
struct jewel {
    int m; int v;
};
int N,K;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N >> K;
    int mi,vi;
    vector<jewel> jwl; vector<int> bag;
    for (int i=0; i<N; ++i) {
        cin >> mi >> vi;
        jwl.push_back({mi, vi});
    }

    for (int i=0; i<K; ++i) {
        int x; cin >> x; bag.push_back(x);
    }

    sort(begin(jwl), end(jwl), [](const jewel& j1, const jewel& j2){ return j1.m < j2.m; });
    sort(begin(bag), end(bag));

    priority_queue<int, vector<int>, less<int>> max_pq;
    ll ans = 0; int cnt = 0;
    for (int i=0; i<K; ++i) {
        while (cnt < N && jwl[cnt].m <= bag[i]) {
            max_pq.push(jwl[cnt].v); ++cnt;
        }

        if (max_pq.empty()) continue;
        ans += max_pq.top(); max_pq.pop();
    }
    cout << ans;
    return 0;
}