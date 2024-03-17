/**
 *    author:  MaGnsi0
 *    created: 13.02.2024 16:59:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int x; cin >> x;
        int y; cin >> y;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        reverse(a.begin(), a.end());
        int64_t ans = 0;
        map<pair<int, int>, int64_t> mp;
        for (int i = 0; i < n; ++i) {
            int needx = (x - (a[i] % x)) % x;
            int needy = (y - (a[i] % y)) % y;
            ans += mp[{needx, needy}];
            mp[{a[i] % x, (y - a[i] % y) % y}]++;
        }
        cout << ans << "\n";
    }
}
