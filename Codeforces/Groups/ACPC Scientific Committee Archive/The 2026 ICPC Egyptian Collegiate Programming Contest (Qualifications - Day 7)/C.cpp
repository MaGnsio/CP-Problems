/**
 *    author:  MaGnsi0
 *    created: 19.08.2026 19:51:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        map<int64_t, int> mp;
        for (int i = 0; i < n; ++i) {
            int64_t x; cin >> x; mp[x]++;
        }
        int64_t v = (mp.begin() -> first) * (mp.rbegin() -> first);
        for (int i = 0; i < n / 2; ++i) {
            int64_t x = mp.begin() -> first;
            int64_t y = v / x;
            cout << x << " " << y << " ";
            if (mp[x] == 1) { mp.erase(x); }
            else { mp[x]--; }
            if (mp[y] == 1) { mp.erase(y); }
            else { mp[y]--; }
        }
        cout << "\n";
    }
}
