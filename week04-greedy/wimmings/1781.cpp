#include <iostream>
#include <vector>
#include <cstring>
#include <memory.h>
#include <algorithm>

using namespace std;
int n, k;
int order[102];
int tap[102];
int ans;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> order[i];
    }

    for (int i = 0; i < k; ++i) {
        bool isUsed = false;

        for (int j = 0; j < n; ++j) { // 이미 꽂혀 있는 기기
            if (tap[j] == order[i]) {
                isUsed = true;
                break;
            }
        }
        if (isUsed) continue;

        for (int j = 0; j < n; ++j) { // 넣을 수 있는 곳에 넣기
            if (!tap[j]) {
                isUsed = true;
                tap[j] = order[i];
                break;
            }
        }
        if (isUsed) continue;

        
        // 여기 왔다는 건 자리 없다는 뜻
        int idx, p = -1;
        for (int j = 0; j < n; j++){
            int pos = 0;
            int next = i + 1;
            while (next < k && tap[j] != order[next]){
                pos++;
                next++;
            }
            if (pos > p){
                idx = j;
                p = pos;
            }
        }
        tap[idx] = order[i];
        ans++;
       
    }
    cout << ans << '\n';
    return 0;
}