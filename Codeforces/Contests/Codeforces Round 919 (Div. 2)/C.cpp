/**
 *    author:  MaGnsi0
 *    created: 20.01.2024 22:14:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        for (int k = 1; k <= n; ++k) {
            if (n % k) { continue; }
            int g = 0;
            for (int i = 0; i + k < n; ++i) {
                g = __gcd(g, abs(a[i] - a[i + k]));
            }
            ans += g != 1;
        }
        cout << ans << "\n";
    }
}
