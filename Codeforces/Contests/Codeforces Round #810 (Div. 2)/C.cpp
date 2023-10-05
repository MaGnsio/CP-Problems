/**
 *    author:  MaGnsi0
 *    created: 24.07.2022 16:34:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int64_t> a(k);
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
        }
        vector<int64_t> b(k), c(k);
        for (int i = 0; i < k; ++i) {
            b[i] = a[i] / m;
            c[i] = a[i] / n;
        }
        sort(b.begin(), b.end(), greater<int64_t>());
        sort(c.begin(), c.end(), greater<int64_t>());
        vector<bool> d(k, false), e(k, false);
        for (int i = 0; i < k; ++i) {
            if (b[i] >= 2 && n >= 2) {
                b[i] -= 2;
                d[i] = true;
                n -= 2;
            }
            if (c[i] >= 2 && m >= 2) {
                c[i] -= 2;
                e[i] = true;
                m -= 2;
            }
        }
        int64_t remn = 0, remm = 0;
        for (int i = 0; i < k; ++i) {
            remn += d[i] * b[i];
            remm += e[i] * c[i];
        }
        cout << (remn >= n || remm >= m ? "YES" : "NO") << "\n";
    }
}
