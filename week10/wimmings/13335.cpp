#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;
int n, w, L;

struct Truck {
    int weight, dist;
};
deque<Truck> deq;
queue<int> trucks;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> w >> L;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        trucks.push(x);
    }
    
    // 초기 설정 : 1번 트럭을 덱에 넣어놓자.
    int ans = 1;                        
    int sum = trucks.front();           // 총 하중은 1번 트럭 무게
    deq.push_back({trucks.front(), 0}); // { 1번 트럭 무게, 이동한 거리 } 덱에 삽입
    trucks.pop();                       // 1번 트럭 pop

    while (!deq.empty() || !trucks.empty()) { // deq과 trucks가 모두 비어있을 때 끝
        for (int i = 0; i < deq.size(); ++i) {
            deq[i].dist++;                    // 덱에 있는 모든 트럭 한 칸씩 이동
        }
        if (deq.front().dist == w) {          // 다리 길이만큼 다 이동했으면 다리 통과 -> sum에서 빼주고 덱에서도 빼주기
            sum -= deq.front().weight;
            deq.pop_front();
        }

        /* 
            덱에 넣는 상황 : trucks가 비어있어도 trucks.front()가 0으로 잡힌다. 
            그래서 비어있는지 체크 그리고 하중 남아있으면 덱에 넣기, 
            근데 위에서 다리 끝까지 간 애는 덱에서 빼주기 때문에 새로 트럭을 넣을 땐 항상 자리가 있긴 함.
        */
        if (!trucks.empty() && sum + trucks.front() <= L) { 
            sum += trucks.front();
            deq.push_back({trucks.front(), 0});
            trucks.pop();
        }
        ans++;
    }
    
    cout << ans << '\n';

    return 0;
}