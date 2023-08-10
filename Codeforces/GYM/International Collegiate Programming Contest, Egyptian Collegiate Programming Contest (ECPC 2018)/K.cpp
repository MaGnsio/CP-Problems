/**
 *    author:  MaGnsi0
 *    created: 25.07.2023 07:28:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("string.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        string s, p;
        cin >> s >> p;
        int n = (int)s.size();
        int m = (int)p.size();
        vector<vector<int64_t>> a(n, vector<int64_t>(m + 1));
        for (int i = 0; i < n; ++i) {
            for (int j = i, k = 0; j < n && k < m; ++j, ++k) {
                if (s[j] != p[k]) { break; }
                a[j][k + 1]++;
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= m; ++j) {
                a[i][j] += a[i - 1][j];
            }
        }
        vector<vector<int64_t>> b(n, vector<int64_t>(m + 1));
        for (int i = 0; i < n; ++i) {
            for (int j = i, k = m - 1; j >= 0 && k >= 0; --j, --k) {
                if (s[j] != p[k]) { break; }
                b[j][m - k]++;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= m; ++j) {
                b[i][j] += b[i + 1][j];
            }
        }
        vector<int64_t> c(n), d(n);
        for (int i = 0; i + m - 1 < n; ++i) {
            if (s.substr(i, m) == p) {
                c[i + m - 1] = i + m - 1;
                d[i] = i + 2;
            }
        }
        for (int i = 1; i < n; ++i) {
            c[i] += c[i - 1];
        }
        for (int i = n - 2; i >= 0; --i) {
            d[i] += d[i + 1];
        }
        int Q;
        cin >> Q;
        while (Q--) {
            int64_t L, R;
            cin >> L >> R;
            int64_t top = (n - R + 1) * (L * a[L - 1][m] - c[L - 1]);
            top += L * (d[R - 1] - R * b[R - 1][m]);
            int64_t bot = (n - R + 1) * L;
            for (int j = 1; j < m; ++j) {
                top += a[L - 1][j] * b[R - 1][m - j];
            }
            int64_t g = __gcd(top, bot);
            cout << top / g << "/" << bot / g << "\n";
        }
    }
}
