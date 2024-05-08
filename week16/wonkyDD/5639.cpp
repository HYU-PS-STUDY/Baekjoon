#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void recur(int s, int e) {
    if (s >= e) return;
    // NOTE : 노드가 1개라면 그냥 탐색하면 된다
    if (s == e-1) {
        cout << v[s] << '\n';
        return;
    }

    int idx = s+1;
    // NOTE : 왼쪽 서브트리에 해당하는 인덱스 범위를 찾는다
    while (idx < e) {
        if (v[s] < v[idx]) break;
        ++idx;
    }

    // NOTE : 후위 순회 : 왼쪽 - 오른쪽 - 루트
    recur(s+1, idx); recur(idx, e); cout << v[s] << '\n';
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int x;
    while (cin >> x) { v.push_back(x); }
    recur(0, v.size());
    return 0;
}