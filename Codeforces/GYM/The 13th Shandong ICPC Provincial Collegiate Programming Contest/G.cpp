/**
 *    author:  MaGnsi0
 *    created: 13.10.2023 19:38:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int64_t, vector<int64_t>> mp;
        for (int i = 0; i < n; ++i) {
            int64_t x; cin >> x;
            mp[x - i].push_back(x);
        }
        int64_t ans = 0;
        for (auto [_, a] : mp) {
            int m = (int)a.size();
            sort(a.rbegin(), a.rend());
            for (int i = 0; i + 1 < m; i += 2) {
                ans += max(a[i] + a[i + 1], int64_t(0));
            }
        }
        cout << ans << "\n";
    }
}
