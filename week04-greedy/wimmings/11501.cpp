#include <iostream>
#include <vector>
#include <cstring>
#include <memory.h>
#include <algorithm>
#include <queue>

using namespace std;
long long n;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long t; cin >> t;
    for (long long i = 0; i < t; ++i) {
        cin >> n;
        vector<long long> v(n);
        for (long long j = n-1; j >= 0; --j) {
            cin >> v[j];
        }
        long long ans = 0;

        long long maxi = -1;
        for (long long j = 0; j < n; ++j) {
            maxi = max(maxi, v[j]);
            ans += maxi - v[j];
        }
        cout << ans << '\n';
    }
    return 0;
}