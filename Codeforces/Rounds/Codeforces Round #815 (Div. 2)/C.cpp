/**
 *    author:  MaGnsi0
 *    created: 18.08.2022 15:34:17
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[8][3] = {{0, -1, -1}, {0, -1, -1}, {0, 1, 1}, {0, 1, 1}, {0, 0, -1}, {0, 0, 1}, {0, 0, -1}, {0, 0, 1}}; 
const int dy[8][3] = {{0, 0, -1}, {0, 0, 1}, {0, 0, -1}, {0, 0, 1}, {0, -1, -1}, {0, -1, -1}, {0, 1, 1}, {0, 1, 1}};

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
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += count(a[i].begin(), a[i].end(), '1');
        }
        if (ans == 0) {
            cout << 0 << "\n";
            continue;
        }
        int miniL = 3;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < 8; ++k) {
                    vector<int> x(3, i), y(3, j);
                    for (int l = 0; l < 3; ++l) {
                        x[l] += dx[k][l];
                        y[l] += dy[k][l];
                    }
                    bool in = true;
                    for (int l = 0; l < 3; ++l) {
                        in &= (0 <= x[l] && x[l] < n);
                        in &= (0 <= y[l] && y[l] < m);
                    }
                    if (!in) {
                        continue;
                    }
                    int L = 0;
                    for (int l = 0; l < 3; ++l) {
                        L += a[x[l]][y[l]] == '1';
                    }
                    if (L) {
                        miniL = min(miniL, L);
                    }
                }
            }
        }
        ans -= miniL - 1;
        cout << ans << "\n";
    }
}
