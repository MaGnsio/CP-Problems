/**
 *    author:  MaGnsi0
 *    created: 28.02.2024 21:30:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int Q; cin >> Q;
        vector<int64_t> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            b[i] = b[i - 1] + (a[i] == 1);
        }
        for (int i = 1; i <= n; ++i) {
            a[i] += a[i - 1];
        }
        while (Q--) {
            int low; cin >> low;
            int high; cin >> high;
            int m = high - low + 1;
            int64_t sum = a[high] - a[low - 1];
            int64_t need = m + b[high] - b[low - 1];
            cout << (m == 1 || sum < need ? "NO" : "YES") << "\n";
        }
    }
}
