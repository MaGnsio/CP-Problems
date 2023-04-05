/**
 *    author:  MaGnsi0
 *    created: 31.03.2023 16:44:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, x, y;
        cin >> n >> x >> y;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        map<int64_t, int64_t> mp;
        for (int i = 0; i < n; ++i) {
            mp[a[i]]++;
        }
        int64_t always_remove = 0;
        for (auto& [_, cnt] : mp) {
            always_remove += x * (cnt - 1);
        }
        int64_t ans = n * x + y, need_to = 0, prev = 0, remaining = (int)mp.size();
        for (auto& [z, cnt] : mp) {
            need_to += z - prev - 1;
            prev = z;
            remaining--;
            ans = min(ans, always_remove + y * need_to + x * remaining);
        }
        cout << ans << "\n";
    }
}
