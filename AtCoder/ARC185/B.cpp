/**
 *    author:  MaGnsi0
 *    created: 13.10.2024 19:41:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool ok = true;
        int64_t sum = accumulate(a.begin(), a.end(), int64_t(0));
        for (int i = 0; i < n; ++i) {
            int64_t val = (sum / n) + ((sum % n) >= (n - i));
            if (a[i] > val) {
                ok = false;
                break;
            } else {
                int64_t diff = val - a[i];
                a[i] += diff;
                if (i != n - 1) {
                    a[i + 1] -= diff;
                }
            }
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }
}
