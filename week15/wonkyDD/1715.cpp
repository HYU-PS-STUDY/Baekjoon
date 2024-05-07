#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
int N;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N;
    // NOTE : 최소힙
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i=0; i<N; ++i) {
        ll x; cin >> x; pq.push(x);
    }

    ll ans = 0;
    while (pq.size() > 1) {
        ll t1 = pq.top(); pq.pop();
        ll t2 = pq.top(); pq.pop();
        ans += t1+t2;
        pq.push(t1+t2);
    }
    cout << ans;

    return 0;
}