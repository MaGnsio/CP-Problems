/**
 *    author:  MaGnsi0
 *    created: 06.08.2024 17:59:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int s; cin >> s;
        int m; cin >> m;
        vector<int> l(n + 2), r(n + 2);
        l[0] = r[0] = 0;
        l[n + 1] = r[n + 1] = m;
        for (int i = 1; i <= n; ++i) {
            cin >> l[i] >> r[i];
        }
        bool ok = false;
        for (int i = 1; i < n + 2; ++i) {
            ok |= l[i] - r[i - 1] >= s;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
