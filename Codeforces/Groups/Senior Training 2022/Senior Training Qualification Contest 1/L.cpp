/**
 *    author:  MaGnsi0
 *    created: 11.03.2022 20:28:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("xorsum.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        int cnt = 0, f = 0;
        for (int i = 0; i < n; ++i) {
            cnt += (s[i] == '1' && t[i] == '1');
            f += (s[i] == '0' && t[i] == '0');
        }
        cout << (cnt > 1 || (cnt == 1 && f == 0) ? "NO\n" : "YES\n");
    }
}
