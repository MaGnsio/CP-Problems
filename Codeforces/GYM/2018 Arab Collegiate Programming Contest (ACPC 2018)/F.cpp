/**
 *    author:  MaGnsi0
 *    created: 26.04.2024 02:56:16
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 305;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("fetiera.in", "r", stdin);
    vector<vector<long double>> C(N, vector<long double>(N));
    for (int i = 0; i < N; ++i) {
        C[i][0] = 1.0;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            assert(C[i][j] >= 0);
        }
    }
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        long double ans = 0, all = 1LL * n * n * (n + 1) * (n + 1) / 4;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                long double p = (i + 1) * (j + 1) * (n - i) * (n - j) / all;
                long double np = 1 - p;
                long double tp = (a[i][j] ? 1 : p);
                long double tnp = (a[i][j] ? powl(np, k) : powl(np, k - 1));
                for (int times = (a[i][j] ? 0 : 1); times <= k; times += 2) {
                    ans += C[k][times] * tp * tnp; 
                    tp = tp * p * p;
                    tnp = (n == 1 ? 0 : tnp / (np * np));
                }
            }
        }
        cout << fixed << setprecision(5) << ans << "\n";
    }
}
