/**
 *    author:  MaGnsi0
 *    created: 07.10.2024 20:01:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t x; cin >> x;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        map<int, multiset<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[a[i] % x].insert(a[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = i % x;
            bool good = false;
            while (!mp[j].empty()) {
                auto it = mp[j].begin();
                if (*it > i) { break; }
                mp[j].erase(it);
                good = true;
                break;
            }
            if (!good) { break; }
            ans++;
        }
        cout << ans << "\n";
    }
}
