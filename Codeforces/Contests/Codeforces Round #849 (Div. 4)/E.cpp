/**
 *    author:  MaGnsi0
 *    created: 03.02.2023 17:38:09
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
        int minus = 0;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            minus += a[i] < 0;
            a[i] = abs(a[i]);
        }
        sort(a.begin(), a.end());
        int64_t ans = accumulate(a.begin(), a.end(), int64_t(0));
        ans -= (minus & 1) * 2 * a[0];
        cout << ans << "\n";
    }
}
