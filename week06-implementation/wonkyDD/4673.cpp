#include <iostream>
using namespace std;
bool filter[10001];

int dn(int n) {
    int sum = 0; int temp = n;
    while (temp) {
        sum += temp%10;
        temp /= 10;
    }
    return sum + n;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    for (int i=1; i<=10000; ++i) {
        if (dn(i) > 10000) continue;
        filter[dn(i)] = true;
    }
    for (int i=1; i<=10000; ++i) {
        if (filter[i]) continue;
        cout << i << '\n';
    }
    return 0;
}