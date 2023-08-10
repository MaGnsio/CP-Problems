/**
 *    author:  MaGnsi0
 *    created: 23.07.2023 02:46:23
**/
#include <bits/stdc++.h>

using namespace std;

#define point complex<long double>

const long double OO = 1e15, eps = 1e-8;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("points.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int64_t L, R;
        cin >> L >> R;
        point a[n];
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            a[i] = {(long double)x, (long double)y};
        }
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            int m = 1;
            map<long double, int> I;
            int p[2 * n + 2];
            vector<long double> b[2 * n + 2];
            for (int j = 0; j < n; ++j) {
                if (i == j) { continue; }
                point v = a[i] - a[j];
                long double s1 = (v.real() ? 1.0 * v.imag() / v.real() : OO);
                if (I[s1] == 0) { I[s1] = m++; }
                long double s2 = (v.imag() ? -1.0 * v.real() / v.imag() : OO);
                if (I[s2] == 0) { I[s2] = m++; }
                p[I[s1]] = I[s2];
                b[I[s1]].push_back(abs(v));
            }
            for (int j = 1; j < m; ++j) {
                sort(b[j].begin(), b[j].end());
            }
            for (int j = 1; j < m; ++j) {
                for (auto d : b[j]) {
                    ans += upper_bound(b[p[j]].begin(), b[p[j]].end(), 2 * R / d + eps)
                         - lower_bound(b[p[j]].begin(), b[p[j]].end(), 2 * L / d - eps);
                }
            }
        }
        cout << ans / 2 << "\n";
    }
}
