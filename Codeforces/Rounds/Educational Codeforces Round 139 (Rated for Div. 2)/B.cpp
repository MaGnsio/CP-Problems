/**
 *    author:  MaGnsi0
 *    created: 12.12.2022 18:56:39
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
        map<string, int> mp;
        for (int i = 0; i + 1 < n; ++i) {
            if (s[i] == s[i + 1]) {
                if (i && s[i - 1] == s[i]) {
                    if (i - 1 && s[i - 2] == s[i]) {
                        mp[s.substr(i, 2)]++;
                    }
                } else {
                    mp[s.substr(i, 2)]++;
                }
            } else {
                mp[s.substr(i, 2)]++;
            }
        }
        bool ok = false;
        for (auto& [_, x] : mp) {
            ok |= x > 1;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
