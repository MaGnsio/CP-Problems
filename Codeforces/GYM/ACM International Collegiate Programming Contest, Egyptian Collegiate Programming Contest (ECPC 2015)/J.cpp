/**
 *    author:  MaGnsi0
 *    created: 20.06.2023 19:13:46
**/
#include <bits/stdc++.h>

using namespace std;

const int m = 26;

bool is_vowel(char x) {
    if (x == 'a') { return true; }
    if (x == 'e') { return true; }
    if (x == 'i') { return true; }
    if (x == 'o') { return true; }
    if (x == 'u') { return true; }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        vector<string> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        function<bool(string, int)> F = [&](string s, int turn) {
            if ((int)s.size() == 1) {
                return is_vowel(s[0]);
            }
            string t = "";
            for (int i = 0; i < (int)s.size(); i += 2) {
                if (i + 1 < (int)s.size()) {
                    t += a[s[i] - 'a'][s[i + 1] - 'a'];
                } else {
                    t += s[i];
                }
            }
            if (F(t, turn ^ 1) == turn) {
                return bool(turn);
            }
            t = "";
            reverse(s.begin(), s.end());
            for (int i = 0; i < (int)s.size(); i += 2) {
                if (i + 1 < (int)s.size()) {
                    t += a[s[i] - 'a'][s[i + 1] - 'a'];
                } else {
                    t += s[i];
                }
            }
            if (F(t, turn ^ 1) == turn) {
                return bool(turn);
            }
            return bool(turn ^ 1);
        };
        string s;
        cin >> s;
        cout << (F(s, 1) ? "Salah" : "Marzo") << "\n";
    }
}
