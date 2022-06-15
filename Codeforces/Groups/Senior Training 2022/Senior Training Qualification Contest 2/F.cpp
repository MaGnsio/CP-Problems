/**
 *    author:  MaGnsi0
 *    created: 12.03.2022 21:22:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("artwork.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> b[i][j];
            }
        }
        vector<vector<int>> p(n, vector<int>(n, 0));
        auto rotatep = [&]() {
            vector<vector<int>> np(n, vector<int>(n));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    np[i][j] = p[j][n - i - 1];
                }
            }
            p = np;
        };
        auto rotateb = [&]() {
            vector<vector<int>> nb(n, vector<int>(n));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    nb[i][j] = b[j][n - i - 1];
                }
            }
            b = nb;
        };
        bool ok = false;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (p == b) {
                    ok = true;
                }
                rotateb();
                rotatep();
                bool can = true;
                for (int x = 0; x < n; ++x) {
                    for (int y = 0; y < n; ++y) {
                        if (a[x][y] == 1 && b[x][y] == 0) {
                            can = false;
                        }
                    }
                }
                if (can) {
                    for (int x = 0; x < n; ++x) {
                        for (int y = 0; y < n; ++y) {
                            if (a[x][y] == 1) {
                                p[x][y] = 1;
                            }
                        }
                    }
                }
            }
            if (b == p) {
                ok = true;
            }
            rotateb();
            p = vector<vector<int>>(n, vector<int>(n, 0));
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
