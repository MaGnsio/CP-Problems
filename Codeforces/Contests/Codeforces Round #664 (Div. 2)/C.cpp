/**
 *    author:  MaGnsi0
 *    created: 21.11.2021 00:25:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    vector<vector<int>> g(n, b);
    for (int i = 10; i >= 0; --i) {
        vector<vector<int>> t(n);
        for (int j = 0; j < n; ++j) {
            if ((1 & (a[j] >> i)) == 0) {
                t[j] = g[j];
                continue;
            }
            vector<int> temp;
            for (int k = 0; k < (int)g[j].size(); ++k) {
                if ((1 & (g[j][k] >> i)) == 0) {
                    temp.push_back(g[j][k]);
                }
            }
            t[j] = temp;
        }
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (t[j].empty()) {
                ok = false;
                break;
            }
        }
        if (ok) {
            g = t;
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res |= (a[i] & g[i][0]);
    }
    cout << res;
}
