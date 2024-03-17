/**
 *    author:  MaGnsi0
 *    created: 28.11.2023 22:02:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t ans = 0;
        map<int, int64_t> mp;
        for (int i = 0; i < n; ++i) {
            ans += mp[a[i]];
            if (a[i] == 1) { ans += mp[2]; }
            if (a[i] == 2) { ans += mp[1]; }
            mp[a[i]]++;
        }
        cout << ans << "\n";
    }
}
