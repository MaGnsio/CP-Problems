/**
 *    author:  MaGnsi0
 *    created: 18.09.2024 21:54:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int Q; cin >> Q;
        int ans  = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; ans = max(ans, x);
        }
        while (Q--) {
            char c; cin >> c;
            int l; cin >> l;
            int r; cin >> r;
            if (l <= ans && ans <= r) {
                ans += (c == '+') - (c == '-');
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}
