#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;
int n, d, k, coupon;

int table[30002];
unordered_map<int, int> series;
int ans = -1;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> d >> k >> coupon;

    for (int i = 0; i < n; ++i) {
        cin >> table[i];
    }

    int right, left = 0;
    for (right = 0; right < k; ++right) {
        series[table[right]]++;
    }
    if (series.find(coupon) != series.end()) { // 쿠폰 이미 포함
        ans = max(ans, (int)series.size());
    }
    else {
        ans = max(ans, (int)series.size()+1); // 쿠폰 없음 +1해서 max
    }
    
    right--; // 위에서 k로 끝났으니 한 칸 이전으로 다시 땡겨주기 (0~k-1)
    for (int i = 0; i < n; ++i) {
        // 일단 left꺼 지워
        series[table[left]]--;
        if (series[table[left]] == 0) series.erase(table[left]); // 0 됐으면 삭제
        left++;
        
        // right꺼 삽입
        right = (right + 1) % n;
        series[table[right]]++;

        if (series.find(coupon) != series.end()) { // 쿠폰 이미 포함
            ans = max(ans, (int)series.size());
        }
        else {
            ans = max(ans, (int)series.size()+1); // 쿠폰 없음 +1해서 max
        }
    }

    cout << ans << '\n';
    return 0;
}