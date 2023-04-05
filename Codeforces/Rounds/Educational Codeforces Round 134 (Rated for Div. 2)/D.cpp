/**
 *    author:  MaGnsi0
 *    created: 20.03.2023 07:58:18
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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int ans = 0;
        for (int bit = 30; bit >= 0; --bit) {
            int x = 0, y = 0;
            for (int i = 0; i < n; ++i) {
                x += (a[i] >> bit) & 1;
                y += (b[i] >> bit) & 1;
            }
            if (n - x != y) { continue; }
            map<int, int> mp;
            for (int i = 0; i < n; ++i) {
                mp[(b[i] & (ans | (1 << bit)))]++;
            }
            bool worked = true;
            for (int i = 0; i < n; ++i) {
                int k = (a[i] & (ans | (1 << bit))) ^ (ans | (1 << bit));
                if (mp[k]) {
                    mp[k]--;
                } else {
                    worked = false;
                }
            }
            if (worked) {
                ans |= (1 << bit);
            }
        }
        cout << ans << "\n";
    }
}
