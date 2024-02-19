#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 50
int N;
int A[MAX], B[MAX];

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N;

    for (int i=0; i<N; ++i) cin >> A[i];
    for (int i=0; i<N; ++i) cin >> B[i];

    sort(A, A+N);
    sort(B, B+N, greater<int>());

    int ans = 0;
    for (int i=0; i<N; ++i) ans += A[i]*B[i];
    cout << ans;
    return 0;
}