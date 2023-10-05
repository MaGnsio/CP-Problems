/**
 *    author:  MaGnsi0
 *    created: 25.07.2023 17:52:18
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
        vector<int64_t> a(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int64_t k = -1, m = 0;
        vector<int64_t> b(n + 1, 0);
        for (int i = 0; i < n - 1; ++i) {
            int64_t x = a[i] - (i ? a[i - 1] : 0);
            if (x > n || b[x]) {
                k = x;
            } else {
                b[x]++;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (b[i] == 0) { k = (k == -1 ? -1LL : k - i), m++; }
        }
        cout << ((k == 0 && m == 2) || (k == -1 && m == 1) ? "YES" : "NO") << "\n";
    }
}
