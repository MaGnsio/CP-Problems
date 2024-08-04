/**
 *    author:  MaGnsi0
 *    created: 04.08.2024 17:40:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<vector<int64_t>> a(2);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            a[x % 2].push_back(x);
        }
        if (a[0].empty() || a[1].empty()) {
            cout << "0\n";
            continue;
        }
        sort(a[0].begin(), a[0].end());
        sort(a[1].begin(), a[1].end());
        int64_t ans = 0, extra = 0, op = a[1].back();
        for (int i = 0; i < (int)a[0].size(); ++i) {
            extra += op < a[0][i];
            op += (op < a[0][i] ? 2LL : 1LL) * a[0][i];
            ans++;
        }
        cout << ans + (extra != 0) << "\n";
    }
}
