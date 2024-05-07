#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> Minus, Plus;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N;

    for (int i=0; i<N; ++i) {
        int x; cin >> x;
        if (x <= 0) Minus.push_back(x);
        else Plus.push_back(x);
    }

    sort(Minus.begin(), Minus.end(), less<int>());
    sort(Plus.begin(), Plus.end(), greater<int>());

    int ans = 0;

    // NOTE : 짝으로 처리하기 때문에 홀수 길이인 경우 마지막 원소를 미리 추가
    if (Minus.size() & 1) ans += Minus.back();
    for (int i=0; i< (int)Minus.size()-1; i+=2) {
        ans += Minus[i] * Minus[i+1];
    }

    if (Plus.size() & 1) ans += Plus.back();
    for (int i=0; i< (int)Plus.size()-1; i+=2) {
        // NOTE : 1일 경우 더하는 것이 더 크다
        if (Plus[i+1] == 1) ans += Plus[i] + Plus[i+1];
        else ans += Plus[i] * Plus[i+1];
    }

    cout << ans;
    return 0;
}