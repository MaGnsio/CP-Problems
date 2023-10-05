/**
 *    author:  MaGnsi0
 *    created: 29.08.2023 14:37:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        vector<bool> hired(n, false);
        for (int b = k - 1; b >= 0; --b) {
            bool can = true;
            for (int i = 0; i < n; ++i) {
                if (!(a[i] >> b & 1) && hired[i]) {
                    can = false;
                    break;
                }
            }
            if (can == false) { continue; }
            ans += (1LL << b);
            for (int i = 0; i < n; ++i) {
                if (!(a[i] >> b & 1)) {
                    hired[i] = true;
                }
            }
        }
        if (ans != (1LL << k) - 1) {
            cout << ans << "\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (!hired[i]) {
                ans--;
                break;
            }
        }
        cout << ans << "\n";
    }
}
