#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N;
int alpha_cnt[26];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    
    cin >> N;
    string s;

    for (int i=0; i<N; ++i) {
        cin >> s;
        int p = 1;
        for (int j=s.length()-1; j>=0; --j) {
            alpha_cnt[s[j] - 'A'] += p;
            p *= 10;
        }
    }

    sort(alpha_cnt, alpha_cnt+26, cmp);

    int ans = 0;
    int d = 9;
    for (int i=0; i<26; ++i) {
        if (alpha_cnt[i] == 0) continue;

        ans += alpha_cnt[i] * d;
        --d;
    }
    cout << ans;
    return 0;
}