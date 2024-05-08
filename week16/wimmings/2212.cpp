#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;
int n, k;
int sum;

vector<int> sensor;
vector<int> diff;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k; 

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        sensor.push_back(x);
    }
    if (n <= k) {
        cout << 0 << '\n';
        return 0;
    }
    sort(sensor.begin(), sensor.end());

    for (int i = 0; i < n-1; ++i) {
        diff.push_back(sensor[i+1]-sensor[i]);
    }
    sort(diff.rbegin(), diff.rend());

    for (int i = 0; i < k-1; ++i) {
        sum += diff[i];
    }
    cout << sensor[n-1]-sensor[0]-sum << '\n';

    return 0;
}