/**
 *    author:  MaGnsi0
 *    created: 28.02.2024 20:59:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t k; cin >> k;
        vector<int64_t> a(n), b(n), I(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i]; b[i] = abs(b[i]);
        }
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&](int i, int j) {
                return b[i] < b[j];
            });
        bool bad = false;
        int64_t sum = 0;
        for (int i : I) {
            sum += a[i];
            int64_t steps = (sum + k - 1) / k;
            bad |= steps > b[i];
        }
        cout << (!bad ? "YES" : "NO") << "\n";
    }
}
