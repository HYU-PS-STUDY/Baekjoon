#include <iostream>
#include <vector>
#include <cstring>
#include <memory.h>
#include <algorithm>

using namespace std;
int n, c;
vector<int> v;
int ans;

bool solve(int mid) {
    int start = v[0];
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (start + mid <= v[i]) {
            cnt++;
            start = v[i];
        }
    }
    return cnt >= c;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int st = 1;
    int en = v[n-1] - v[0];

    while (st <= en) {
        int mid = (st + en)/2;
        if (solve(mid)) {
            ans = max(ans, mid); // 가장 인접한 두 공유기 사이의 거리를 최대로
            st = mid + 1;
        }
        else en = mid - 1;
    }
    cout << ans << '\n';

    return 0;
}