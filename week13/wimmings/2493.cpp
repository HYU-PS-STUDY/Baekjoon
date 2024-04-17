#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;
typedef pair<int, int> pii; 
int n;
int h[500002];
int ans[500002];

stack<pii> st; // {번호, 높이}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    st.push({0, 100000001}); // 수신호 안 닿을 때 0

    for (int i = n; i >= 0; --i) {
        while (!st.empty() && h[i] >= st.top().second) { 
            // 우리가 보고 있는 건물 i의 높이가 스택에 있는 애들의 높이보다 크면 이 애들의 레이저가 i 건물에 닿는다는 소리. 
            ans[st.top().first] = i;
            st.pop();
        }
        // 스택에 아무것도 없거나, i의 높이가 스택top 건물의 높이보다 작아질 때 stack에 넣는데, 
        // 나중에 자기보다 큰 건물(수신탑)이 나올 때 pop되면서 "ans[자기번호] = 큰 건물(수신탑)번호" 를 적게됨
        st.push({i, h[i]});
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}