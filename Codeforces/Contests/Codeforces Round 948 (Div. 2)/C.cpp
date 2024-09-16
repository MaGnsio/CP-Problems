/**
 *    author:  MaGnsi0
 *    created: 16.09.2024 21:15:02
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
        sort(a.begin(), a.end());
        bool all = false;
        for (int i = 0; i < n; ++i) {
            all |= a[n - 1] % a[i];
        }
        if (all) {
            cout << n << "\n";
            continue;
        }
        int ans = 0;
        set<int> s(a.begin(), a.end());
        function<int(int)> F = [&](int x) {
            if (s.count(x)) { return 0; }
            int c = 0, g = 1;
            for (int y : a) {
                if (x % y == 0) {
                    g = g / __gcd(g, y) * y; c++;
                }
            }
            return g == x ? c : 0;
        };
        for (int64_t x = 1; x * x <= a[n - 1]; ++x) {
            if (a[n - 1] % x == 0) {
                ans = max({ans, F(x), F(a[n - 1] / x)});
            }
        }
        cout << ans << "\n";
    }
}
