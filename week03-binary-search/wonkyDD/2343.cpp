#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int total = 0;
    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        int x; cin >> x; v.push_back(x);
        total += x;
    }

    int l = *max_element(begin(v), end(v)), r = total;
    while (l <= r) {
        int mid = (l+r) / 2;
        int sum = 0;
        int cnt = 0;

        for (int i=0; i<N; ++i) {
            if (sum + v[i] > mid) {
                sum = 0;
                ++cnt;
            }
            sum += v[i];
        }
        if (sum != 0) ++cnt;

        if (cnt > M) l = mid+1;
        else r = mid-1;
    }
    cout << l;
    return 0;
}