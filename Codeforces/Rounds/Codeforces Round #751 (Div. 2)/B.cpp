/**
 *    author:  MaGnsi0
 *    created: 11.11.2021 16:06:41
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 3;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), f(N, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            f[a[i]]++;
        }
        vector<vector<int>> t(N, vector<int>(n));
        t[0] = a;
        for (int i = 1; i < N; ++i) {
            vector<int> nf(N, 0);
            for (int j = 0; j < n; ++j) {
                t[i][j] = f[t[i - 1][j]];
                nf[t[i][j]]++;
            }
            f = nf;
        }
        auto works = [=]() {
            bool ok = true;
            for (int j = 0; j < n; ++j) {
                if (t[N - 1][j] != f[t[N - 1][j]]) {
                    ok = false;
                    break;
                }
            }
            return ok;
        };
        assert(works());
        int q;
        cin >> q;
        while (q--) {
            int x, k;
            cin >> x >> k;
            k = min(k, N - 1);
            cout << t[k][x - 1] << "\n";
        }
    }
}
