#include <iostream>
#include <vector>
#include <cstring>
#include <memory.h>
#include <algorithm>

using namespace std;
int n, m;
vector<int> v;
int ans;

bool solve(int mid) {
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] < mid) {
            cur += v[i];
        } else {
            cur += mid;
        }
    }
    return cur <= m;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    cin >> m;
    int st = 1;
    int en = v[n-1];
    while (st <= en) {
        int mid = (st + en)/2;
        if (solve(mid)) {
            ans = mid;
            st = mid + 1;
        } 
        else en = mid - 1;
    }
    cout << ans << '\n';

    return 0;
}