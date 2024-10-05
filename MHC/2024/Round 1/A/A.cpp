/**
 *    author:  MaGnsi0
 *    created: 05.10.2024 20:02:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int n; cin >> n;
        double vl = 1e-6, vr = 1e18;
        for (int d = 1; d <= n; ++d) {
            int tl; cin >> tl;
            int tr; cin >> tr;
            vl = max(vl, 1.0 * d / tr);
            if (tl) { vr = min(vr, 1.0 * d / tl); }
        }
        if (isgreater(vl, vr)) {
            cout << -1 << "\n";
        } else {
            cout << fixed << setprecision(8) << vl << "\n";
        }
    }
}
