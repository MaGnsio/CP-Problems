/**
 *    author:  MaGnsi0
 *    created: 17.12.2024 21:53:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector a(n, vector<int>(m)), b(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j]; a[i][j]--;
                b[i][a[i][j]] = j;
            }
        }
        map<vector<int>, int> P;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                vector<int> p(b[i].begin(), b[i].begin() + j + 1);
                P[p]++;
            }
        }
        for (int i = 0; i < n; ++i) {
            int res = 0;
            for (int j = 0; j < m; ++j) {
                vector<int> p(a[i].begin(), a[i].begin() + j + 1);
                if (P.count(p) && P[p] > 0) { res = j + 1; }
            }
            cout << res << " ";
        }
        cout << "\n";
    }
}
