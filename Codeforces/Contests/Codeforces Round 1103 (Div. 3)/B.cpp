/**
 *    author:  MaGnsi0
 *    created: 18.06.2026 00:07:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        string s; cin >> s;
        for (int i = 0; i + k < n; ++i) {
            if (s[i] == '1') {
                s[i] = '0';
                s[i + k] = s[i + k] == '0' ? '1' : '0';
            }
        }
        cout << (count(s.begin(), s.end(), '0') == n ? "YES" : "NO") << "\n";
    }
}
