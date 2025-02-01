/**
 *    author:  MaGnsi0
 *    created: 01.02.2025 16:06:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<string> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    for (int i1 = 0; i1 + m - 1 < n; ++i1) {
        for (int j1 = 0; j1 + m - 1 < n; ++j1) {
            bool ok = true;
            for (int i2 = 0; i2 < m; ++i2) {
                for (int j2 = 0; j2 < m; ++j2) {
                    ok = ok && a[i1 + i2][j1 + j2] == b[i2][j2];
                }
            }
            if (ok) {
                cout << i1 + 1 << " " << j1 + 1 << "\n";
                return 0;
            }
        }
    }
}
