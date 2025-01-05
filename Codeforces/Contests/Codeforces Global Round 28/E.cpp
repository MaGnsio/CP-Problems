/**
 *    author:  MaGnsi0
 *    created: 05.01.2025 02:26:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        if (m > 2 * n - 1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector<int> p(2 * n);
        for (int i = 0; i < 2 * n; i += 2) {
            p[i] = p[i + 1] = (i / 2) + 1;
        }
        vector ans(2 * n, vector<int>(m));
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < 2 * n; ++i) {
                ans[i][j] = p[i];
            }
            int x = p[0];
            p.erase(p.begin()); p.push_back(x);
        }
        for (int i = 0; i < 2 * n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
