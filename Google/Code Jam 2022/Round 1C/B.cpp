/**
 *    author:  MaGnsi0
 *    created: 30.04.2022 10:59:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, k;
        cin >> n >> k;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t sum = 0, sumsq = 0, sump = 0;
        for (int i = 0; i < n; ++i) {
            sum += (int64_t)a[i];
            sumsq += (int64_t)a[i] * a[i];
            for (int j = i + 1; j < n; ++j) {
                sump += a[i] * a[j];
            }
        }
        cout << "Case #" << t << ": ";
        if (k == 1) {
            if (sum && (sumsq - sum * sum) % (2 * sum) == 0) {
                cout << (sumsq - sum * sum) / (2 * sum) << "\n";
            } else if (!sumsq) {
                cout << (int64_t)1e18 << "\n";
            } else {
                cout << "IMPOSSIBLE\n";
            }
        } else {
            cout << 1 - sum << " " << -(sump + sum * (1 - sum)) << "\n";
        }
    }
}
