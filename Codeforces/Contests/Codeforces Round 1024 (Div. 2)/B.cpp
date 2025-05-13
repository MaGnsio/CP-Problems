/**
 *    author:  MaGnsi0
 *    created: 13.05.2025 19:38:35
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
        function<bool()> F = [&]() {
            int need_less = (n + 1) / 2 - 1, always_less = 0, always_more = 0;
            for (int i = 1; i < n; ++i) {
                if (a[i] < a[0] && -a[i] < a[0]) {
                    always_less++;
                } else if (a[i] > a[0] && -a[i] > a[0]) {
                    always_more++;
                }
            }
            a[0] *= -1;
            return always_less <= need_less && need_less <= n - always_more - 1;
        };
        cout << (F() || F() ? "YES" : "NO") << "\n";
    }
}
