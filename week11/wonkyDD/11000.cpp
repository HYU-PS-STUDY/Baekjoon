#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int N;
vector<pii> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N;
    int s,t;
    for (int i=0; i<N; ++i) {
        cin >> s >> t;
        v.push_back({s, t});
    }
    // NOTE : 수업의 시작 시간을 기준으로 오름차순 정렬한다
    sort(v.begin(), v.end());

    // NOTE : 첫번째 수업은 강의실에 넣고 시작
    pq.push(v[0].second);

    for (int i=1; i<N; ++i) {
        int t = pq.top();
        // NOTE : 똑같은 강의실에 넣을 수 있다 (다음 수업 시작 시간 >= 현재 수업 끝나는 시간)
        if (v[i].first >= t) pq.pop();
        pq.push(v[i].second);
    }

    // NOTE : 큐에서 pop되지 못하고 남아있는 끝나는 시간 개수만큼 답이다
    cout << pq.size();
    return 0;
}
