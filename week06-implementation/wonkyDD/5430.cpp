#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        string p, num; int n;
        cin >> p; cin >> n; cin >> num;
        string t = "";
        deque<int> dq;

        for (int i=0; i<num.length(); ++i) {
            if (num[i] == '[' || num[i] == ']') continue;
            if (num[i] == ',') {
                dq.push_back(stoi(t));
                t.clear();
            }
            else t += num[i];
        }

        if (!t.empty()) dq.push_back(stoi(t));

        bool is_front = true;
        bool err = false;
        for (int i=0; i<p.length(); ++i) {
            if (p[i] == 'R') {
                is_front = !is_front;
            }
            else {
                if (dq.empty()) {
                    err = true;
                    break;
                }
                if (is_front) dq.pop_front();
                else dq.pop_back();
            }
        }

        if (err) {
            cout << "error" << '\n';
        }
        else {
            string ans = "[";
            if (is_front) {
                while (!dq.empty()) {
                    int x = dq.front();
                    ans += to_string(x) + ",";
                    dq.pop_front();
                }
            }
            else {
                while (!dq.empty()) {
                    int x = dq.back();
                    ans += to_string(x) + ",";
                    dq.pop_back();
                }
            }
            if (ans[ans.length()-1] == ',') ans[ans.length()-1] = ']';
            else ans += ']';
            cout << ans << '\n';
        }
    }
    return 0;
}