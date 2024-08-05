/**
 *    author:  MaGnsi0
 *    created: 06.06.2024 17:53:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> k(n);
        for (int i = 0; i < n; ++i) {
            cin >> k[i];
        }
        int64_t total = 998244353;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = (total + k[i] - 1) / k[i];
        }
        int64_t sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            assert(a[i] * k[i] > total);
        }
        if (sum > total) {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
