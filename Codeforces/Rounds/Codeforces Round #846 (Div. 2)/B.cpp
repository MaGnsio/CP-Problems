/**
 *    author:  MaGnsi0
 *    created: 25.01.2023 16:54:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        int64_t ans = 1;
        for (int i = 0; i < n - 1; ++i) {
            ans = max(ans, __gcd(a[i], a[n - 1] - a[i]));
        }
        cout << ans << "\n";
    }
}
