/**
 *    author:  MaGnsi0
 *    created: 09.04.2023 16:55:17
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
        for (int i = 1; i + 1 < n; ++i) {
            int64_t x = a[i] - a[i - 1];
            if (x < 0) {
                a[i] -= x; 
                a[i + 1] -= x;
            }
        }
        for (int i = n - 2; i > 0; --i) {
            int64_t x = a[i] - a[i + 1];
            if (x > 0) {
                a[i] -= x;
                a[i - 1] -= x;
            }
        }
        cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << "\n";
    }
}
