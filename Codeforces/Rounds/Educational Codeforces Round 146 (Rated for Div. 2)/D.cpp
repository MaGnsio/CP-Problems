/**
 *    author:  MaGnsi0
 *    created: 16.04.2023 06:06:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int64_t> f(n), d(n), p(n);
        for (int i = 0; i < n; ++i) {
            cin >> f[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
        }
        for (int i = 0; i < n; ++i) {
            p[i] = f[i] * d[i];
        }
        int ans = n;
        for (int i = 0; i < n; ++i) {
            vector<int> a(2 * k + 1);
            vector<vector<int>> b(2 * k + 1);
            for (int j = 0; j < n; ++j) {
                int64_t x = max(p[i] / f[j], 1LL);
                if (p[i] - k <= p[j] && p[j] <= p[i] + k) {
                    a[p[j] - p[i] + k]++;
                    b[p[j] - p[i] + k].push_back(j);
                }
                {
                    int64_t new_p = x * f[j];
                    if (new_p != p[j] && p[i] - k <= new_p && new_p <= p[i] + k) {
                        b[new_p - p[i] + k].push_back(j);
                    }
                }
                x++;
                {
                    int64_t new_p = x * f[j];
                    if (new_p != p[j] && p[i] - k <= new_p && new_p <= p[i] + k) {
                        b[new_p - p[i] + k].push_back(j);
                    }
                }
            }
            vector<int> c(n, 0);
            int total = 0, fixed = 0;
            for (int j = 0; j <= k; ++j) {
                fixed += a[j];
                for (int x : b[j]) {
                    total += c[x]++ == 0;
                }
            }
            if (total == n) {
                ans = min(ans, n - fixed);
            }
            for (int j = k + 1; j <= 2 * k; ++j) {
                fixed -= a[j - k - 1]; 
                for (int x : b[j - k - 1]) {
                    total -= --c[x] == 0;
                }
                fixed += a[j];
                for (int x : b[j]) {
                    total += c[x]++ == 0;
                }
                if (total == n) {
                    ans = min(ans, n - fixed);
                }
            }
        }
        cout << ans << "\n";
    }
}
