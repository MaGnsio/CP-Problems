/**
 *    author:  MaGnsi0
 *    created: 30.09.2023 15:44:40
**/
#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string s) {
    int n = (int)s.size();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

bool is_alt(string s) {
    int n = (int)s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] != s[i % 2]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    if (!is_palindrome(s)) {
        cout << 1;
    } else if (is_alt(s)) {
        if ((n & 1) || (s[0] == s[1])) {
            cout << -1;
        } else {
            cout << n / 2;
        }
    } else {
        cout << 2;
    }
}
