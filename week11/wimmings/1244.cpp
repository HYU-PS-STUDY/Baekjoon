#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;
int n, m;
bool swi[102];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> swi[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int student, num; cin >> student >> num;
        if (student == 1) {
            // 남학생
            for (int idx = num; idx <= n; idx+=num) {
                swi[idx] = !swi[idx];
            }
        }
        else {
            // 여학생
            swi[num] = !swi[num];
            int l = num-1;
            int r = num+1;
            while (l >= 1 && r <= n && swi[l]==swi[r]) {
                swi[l] = !swi[l];
                swi[r] = !swi[r];
                l--;
                r++;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cout << swi[i] << " ";
        cnt++;
        if (cnt == 20) {
            cout << '\n';
            cnt = 0;
        }
    }

    return 0;
}