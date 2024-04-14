#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;
int n, k;
int map[200002];
int cnt[100002];


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> map[i];
    }
    int en = 0;
    int ans = -1;

    for (int st = 0; st < n; ++st) {
        while (cnt[map[en]]+1 <= k && en < n) {
            cnt[map[en]]++;
            en++;
        }
        if (en == n) {
            ans = max(ans, en-st);
            break;
        }
        
        ans = max(ans, en-st);
        cnt[map[st]]--;
    }
    cout << ans << '\n';

    return 0;
}