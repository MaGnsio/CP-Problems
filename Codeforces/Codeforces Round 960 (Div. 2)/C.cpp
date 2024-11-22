/**
 *    author:  MaGnsi0
 *    created: 22.11.2024 18:37:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t ans = 0;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; ans += a[i];
        }
        function<void()> process = [&]() {
            int64_t mad = 0;
            vector<int> F(n + 1, 0);
            for (int i = 0; i < n; ++i) {
                if (++F[a[i]] > 1) {
                    mad = max(mad, a[i]);
                }
                a[i] = mad; ans += a[i];
            }
        };
        process(); process();
        for (int i = 0; i < n; ++i) {
            ans += a[i] * (n - i - 1);
        }
        cout << ans << "\n";
    }
}
