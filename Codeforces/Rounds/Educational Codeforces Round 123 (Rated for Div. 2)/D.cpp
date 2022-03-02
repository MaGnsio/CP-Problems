/**
 *    author:  MaGnsi0
 *    created: 22.02.2022 17:11:02
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, MOD = 998244353;

vector<int> r(N, -1), c(N, -1);
vector<int> lastc(N, -1), lastr(N, -1);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k, q;
        cin >> n >> m >> k >> q;
        vector<int> a(q), b(q);
        for (int i = 0; i < q; ++i) {
            cin >> a[i] >> b[i];
        }
        int cntr = 0, cntc = 0;
        long long ans = 1;
        for (int i = q - 1; i >= 0; --i) {
            if (cntc < m && cntr < n) {
                if (lastc[a[i] - 1] == -1) {
                    lastc[a[i] - 1] = b[i] - 1;
                    if (lastr[b[i] - 1] != a[i] - 1) {
                        ans *= 1LL * k;
                        ans %= MOD;
                    }
                }
            }
            if (cntr < n && cntc < m) {
                if (lastr[b[i] - 1] == -1) {
                    lastr[b[i] - 1] = a[i] - 1;
                    if (lastc[a[i] - 1] != b[i] - 1) {
                        ans *= k;
                        ans %= MOD;
                    }
                }
            }
            if (r[a[i] - 1] != T) {
                cntr++;
            }
            if (c[b[i] - 1] != T) {
                cntc++;
            }
            r[a[i] - 1] = T, c[b[i] - 1] = T;
            if (cntr == n || cntc == m) {
                break;
            }
        }
        for (int i = 0; i < q; ++i) {
            lastc[a[i] - 1] = -1;
            lastr[b[i] - 1] = -1;
        }
        cout << ans << "\n";
    }
}
