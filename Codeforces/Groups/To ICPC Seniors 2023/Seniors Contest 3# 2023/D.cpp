/**
 *    author:  MaGnsi0
 *    created: 06.02.2023 09:09:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("largest.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, ans = INT64_MIN;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int64_t x;
            cin >> x;
            ans = max(ans, x);
        }
        cout << ans << "\n";
    }
}
