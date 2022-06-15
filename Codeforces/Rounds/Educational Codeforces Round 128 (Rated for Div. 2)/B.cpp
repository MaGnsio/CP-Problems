/**
 *    author:  MaGnsi0
 *    created: 13.05.2022 16:34:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 'R') {
                    bool nice = true;
                    for (int k = 0; k < n; ++k) {
                        for (int l = 0; l < m; ++l) {
                            if (a[k][l] == 'R') {
                                if (k - i < 0 || l - j < 0) {
                                    nice = false;
                                }
                            }
                        }
                    }
                    ok |= nice;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
