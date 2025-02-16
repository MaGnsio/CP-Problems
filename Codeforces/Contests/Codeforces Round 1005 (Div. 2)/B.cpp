/**
 *    author:  MaGnsi0
 *    created: 16.02.2025 16:44:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n), f(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; a[i]--; f[a[i]]++;
        }
        vector<pair<int, int>> ops;
        for (int i = 0, l = -1, r = -1; i < n; ++i) {
            if (f[a[i]] != 1) {
                if (l != -1) {
                    ops.emplace_back(l, r);
                }
                l = r = -1;
                continue;
            }
            if (l == -1) {
                l = r = i;
            } else {
                r = i;
            }
            if (i == n - 1 && l != -1) {
                ops.emplace_back(l, r);
            }
        }
        sort(ops.begin(), ops.end(), [](pair<int, int> x, pair<int, int> y) {
            return x.second - x.first > y.second - y.first;
        });
        if (ops.empty()) {
            cout << "0\n";
        } else {
            cout << ops[0].first + 1 << " " << ops[0].second + 1 << "\n";
        }
    }
}
