#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string s; getline(cin, s);
    string ans = "";

    bool open_flag = false;
    string str = "";
    for (int i = 0; i < s.length(); ++i) {    
        if (s[i] == '<') {
            open_flag = true;
            if (str.length() > 0) {
                for (int j = str.length()-1; j >= 0; --j) {
                    ans += str[j];
                }
                str = "";
            }
            ans += "<";
        }
        else if (s[i] == '>') {
            str += s[i];
            ans += str;
            str = "";
            open_flag = false;
        }
        else if (s[i] == ' ') {
            if (open_flag) {
                str += " ";
            }
            else {
                for (int j = str.length()-1; j >= 0; --j) {
                    ans += str[j];
                }
                ans += " ";
                str = "";
            }
        }
        else {
            str += s[i];
        }
    }
    // 마지막 문자열
    for (int j = str.length()-1; j >= 0; --j) {
        ans += str[j];
    }
    cout << ans << '\n';
    return 0;
}