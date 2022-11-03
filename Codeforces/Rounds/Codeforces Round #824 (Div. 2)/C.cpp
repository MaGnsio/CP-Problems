/**
 *    author:  MaGnsi0
 *    created: 02.10.2022 23:53:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        vector<char> nxt(26, '0'), ans(26, '0');
        function<bool(char, char)> F = [&](char v, char x) {
            if (v == x) { return false; }
            if (v == '0') { return true; }
            return F(nxt[v - 'a'], x);
        };
        for  (int i = 0; i < n; ++i) {
            if (ans[s[i] - 'a'] != '0') { continue; }
            for (int j = 0; j < 26; ++j) {
                if (nxt[j] == '0' && F(s[i], char('a' + j))) {
                    nxt[j] = s[i];
                    ans[s[i] - 'a'] = char('a' + j);
                    break;
                }
            }
        }
        set<char> _s;
        for (int i = 0; i < 26; ++i) {
            _s.insert(char('a' + i));
        }
        for (int i = 0; i < 26; ++i) {
            _s.erase(ans[i]);
        }
        for (int i = 0; i < 26; ++i) {
            if (ans[i] == '0') {
                ans[i] = *_s.begin();
                _s.erase(_s.begin());
            }
        }
        for (int i = 0; i < n; ++i) {
            s[i] = ans[s[i] - 'a'];
        }
        cout << s << "\n";
    }
}
