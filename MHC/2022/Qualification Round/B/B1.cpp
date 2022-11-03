/**
 *    author:  MaGnsi0
 *    created: 29.08.2022 16:46:19
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[4][4] = {{0, 0, 1, 1}, {0, 0, 1, 1}, {0, 0, -1, -1}, {0, 0, -1, -1}};
const int dy[4][4] = {{0, 1, 0, 1}, {0, -1, 0, -1}, {0, 1, 0, 1}, {0, -1, 0, -1}};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("B1.in", "r", stdin);
    freopen("B1.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] != '^') {
                    continue;
                }
                bool works = false;
                for (int k = 0; k < 4; ++k) {
                    bool good = true;
                    for (int l = 0; l < 4; ++l) {
                        int ni = i + dx[k][l]; 
                        int nj = j + dy[k][l];
                        good &= (0 <= ni && ni < n && 0 <= nj && nj < m && a[ni][nj] != '#');
                    }
                    if (!good) {
                        continue;
                    }
                    works = true;
                    for (int l = 0; l < 4; ++l) {
                        a[i + dx[k][l]][j + dy[k][l]] = '^';
                    }
                    break;
                }
                ok &= works;
            }
        }
        cout << "Case #" << t << ": ";
        if (ok) {
            cout << "Possible\n";
            for (int i = 0; i < n; ++i) {
                cout << a[i] << "\n";
            }
        } else {
            cout << "Impossible\n";
        }
    }
}
