/**
 *    author:  MaGnsi0
 *    created: 15.06.2024 18:25:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t ans = 0, sum = 0, maxx = 0;
        for (int i = 0; i < n; ++i) {
            int64_t x; cin >> x;
            sum += x;
            maxx = max(maxx, x);
            ans += sum - maxx == maxx;
        }
        cout << ans << "\n";
    }
}
