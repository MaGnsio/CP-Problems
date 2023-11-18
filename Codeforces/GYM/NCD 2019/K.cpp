/**
 *    author:  MaGnsi0
 *    created: 15.10.2023 21:58:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, x;
        cin >> n >> x;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t ans = 0, sum = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            while (sum >= x) { sum -= a[j++]; }
            ans += i - j + 1;
        }
        cout << ans << "\n";
    }
}
