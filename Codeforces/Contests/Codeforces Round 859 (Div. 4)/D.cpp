/**
 *    author:  MaGnsi0
 *    created: 20.03.2023 02:10:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int64_t> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        for (int i = 0; i < q; ++i) {
            int64_t l, r, k;
            cin >> l >> r >> k;
            int64_t sum = a[n] - a[r] - a[l - 1] + (r - l + 1) * k;
            cout << (sum & 1 ? "YES" : "NO") << "\n";
        }
    }
}
