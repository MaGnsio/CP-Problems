/**
 *    author:  MaGnsi0
 *    created: 30.05.2024 17:36:02
**/
#include <bits/stdc++.h>

using namespace std;

bool is_letter(char c) {
    return 'a' <= c && c <= 'z';
}

bool is_digit(char c) {
    return '0' <= c && c <= '9';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        bool good = true;
        for (int i = 0; i < n; ++i) {
            if (is_digit(s[i])) {
                if (i && is_letter(s[i - 1])) {
                    good = false;
                } else if (i && is_digit(s[i - 1]) && s[i - 1] > s[i]) {
                    good = false;
                }
            } else if (is_letter(s[i])) {
                if (i && is_letter(s[i - 1]) && s[i - 1] > s[i]) {
                    good = false;
                }
            } else {
                good = false;
            }
        }
        cout << (good ? "YES" : "NO") << "\n";
    }
}
