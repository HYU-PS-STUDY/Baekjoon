#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N;
    for (int i=0; i<N; ++i) {
        int x; cin >> x; v.push_back(x);
    }
    sort(begin(v), end(v));

    int ans = 0;
    for (int i=0; i<N; ++i) {
        int start = 0, end = v.size()-1;
        while (start < end) {
            if (start == i) { ++start; continue; }
            if (end == i) { --end; continue; }

            int sum = v[start]+v[end];
            if (sum == v[i]) { ++ans; break; }

            if (sum > v[i]) --end;
            else ++start;
        }
    }
    cout << ans;
    return 0;
}