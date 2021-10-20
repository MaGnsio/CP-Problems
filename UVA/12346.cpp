/**
 *    author:  MaGnsi0
 *    created: 10/09/2021 22:04:50
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<long long> F(n), D(n);
    for (int i = 0; i < n; ++i) {
        cin >> F[i] >> D[i];
    }
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        long long v, t;
        cin >> v >> t;
        for (int i = 0; i < n; ++i) {
            F[i] *= t;
        }
        long long res = LLONG_MAX;
        for (int i = 0; i < (1 << n); ++i) {
            long long x = 0, y = 0;
            for (int j = 0; j < n; ++j) {
                if ((1 << j) & i) {
                    x += F[j];
                    y += D[j];
                }
            }
            if (x >= v) {
                res = min(res, y);
            }
        }
        for (int i = 0; i < n; ++i) {
            F[i] /= t;
        }
        cout << "Case " << tc << ": ";
        if (res == LLONG_MAX) {
            cout << "IMPOSSIBLE";
        } else {
            cout << res;
        }
        cout << "\n";
    }
}
