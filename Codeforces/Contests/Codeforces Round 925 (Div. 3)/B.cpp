/**
 *    author:  MaGnsi0
 *    created: 13.02.2024 16:51:41
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
        int64_t x = accumulate(a.begin(), a.end(), int64_t(0)) / n;
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] > x) {
                a[i + 1] += a[i] - x;
                a[i] = x;
            }
        }
        cout << (count(a.begin(), a.end(), x) == n ? "YES" : "NO") << "\n";
    }
}
