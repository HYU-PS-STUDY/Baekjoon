#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;
int T;

bool isPalindrome(string str) {
    int l = 0;
    int r = str.length()-1;
    while (l < r) {
        if (str[l] != str[r]) return false;
        l++;
        r--;
    }
    return true;
}

bool isPseudo(string str) {
    int l = 0;
    int r = str.length()-1;
    bool del = false;

    while (l < r) {
        if (str[l] != str[r]) {
            
            if (str[l+1] == str[r]) {
                del |= isPalindrome(str.substr(l+1, r-l));
            }
            if (str[l] == str[r-1]) {
                del |= isPalindrome(str.substr(l, r-l));
            }
            return del;
        }
        
        l++;
        r--;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string str; cin >> str;
        if (isPalindrome(str)) {
            cout << 0 << '\n';
            continue;
        }
        if (isPseudo(str)) {
            cout << 1 << '\n';
            continue;
        }
        cout << 2 << '\n';
    }
    return 0;
}