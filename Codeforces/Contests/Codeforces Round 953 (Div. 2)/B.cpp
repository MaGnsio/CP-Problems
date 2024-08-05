/**
 *    author:  MaGnsi0
 *    created: 17.06.2024 16:05:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t a; cin >> a;
        int64_t b; cin >> b;
        int64_t take = min(max(b - a, 0LL), n);
        int64_t ans = take * b - take * (take - 1) / 2 + (n - take) * a;
        cout << ans << "\n";
    }
}
