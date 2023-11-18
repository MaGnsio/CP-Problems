/**
 *    author:  MaGnsi0
 *    created: 02.11.2023 11:12:18
**/
#include <bits/stdc++.h>

using namespace std;

bool palindrome(string s) {
    int n = (int)s.size();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = (int)s.size();
    string t = "";
    for (int i = 0; i < n; ++i) {
        string x = s; x += t;
        if (palindrome(x)) { break; }
        reverse(t.begin(), t.end());
        t += s[i];
        reverse(t.begin(), t.end());
    }
    cout << s << t;
}
