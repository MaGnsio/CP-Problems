/**
 *    author:  MaGnsi0
 *    created: 20.08.2024 17:39:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; mp[x]++;
        }
        int ans = n - 1;
        for (auto [_, c] : mp) {
            ans = min(ans, n - c);
        }
        cout << ans << "\n";
    }
}
