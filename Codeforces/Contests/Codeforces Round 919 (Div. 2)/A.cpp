/**
 *    author:  MaGnsi0
 *    created: 20.01.2024 22:02:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int low = 1, high = 1e9;
        set<int> bad;
        for (int i = 0; i < n; ++i) {
            int t; cin >> t;
            int x; cin >> x;
            if (t == 1) {
                low = max(low, x);
            } else if (t == 2) {
                high = min(high, x);
            } else {
                bad.insert(x);
            }
        }
        if (low > high) {
            cout << 0 << "\n";
            continue;
        }
        int ans = high - low + 1;
        for (int x : bad) {
            ans -= low <= x && x <= high;
        }
        cout << ans << "\n";
    }
}
