/**
 *    author:  MaGnsi0
 *    created: 01.09.2024 15:19:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> deg(n);
        for (int i = 0; i < n - 1; ++i) {
            int u; cin >> u; deg[u - 1]++;
            int v; cin >> v; deg[v - 1]++;
        }
        string s; cin >> s;
        int one = 0, zero = 0, qmark = 0;
        for (int i = 1; i < n; ++i) {
            one += (deg[i] == 1) * (s[i] == '1');
            zero += (deg[i] == 1) * (s[i] == '0');
            qmark += (deg[i] == 1) * (s[i] == '?');
        }
        if (s[0] != '?') {
            cout << (s[0] == '0' ? one : zero) + (qmark + 1) / 2 << "\n";
        } else {
            int ans = max(one, zero) + qmark / 2;
            if (one == zero && (count(s.begin(), s.end(), '?') - qmark) % 2 == 0) {
                ans = max(ans, zero + (qmark + 1) / 2);
            }
            cout << ans << "\n";
        }
    }
}
