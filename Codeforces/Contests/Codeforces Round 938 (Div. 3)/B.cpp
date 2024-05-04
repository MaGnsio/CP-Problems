/**
 *    author:  MaGnsi0
 *    created: 11.04.2024 18:23:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t x; cin >> x;
        int64_t y; cin >> y;
        vector<int64_t> a(n * n);
        for (int i = 0; i < n * n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<vector<int64_t>> b(n, vector<int64_t>(n));
        b[0][0] = a[0];
        for (int i = 1; i < n; ++i) {
            b[i][0] = b[i - 1][0] + x;
        }
        for (int j = 1; j < n; ++j) {
            b[0][j] = b[0][j - 1] + y;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                b[i][j] = b[i - 1][j] + x;
            }
        }
        vector<int64_t> c;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                c.push_back(b[i][j]);
            }
        }
        sort(c.begin(), c.end());
        cout << (a == c ? "YES" : "NO") << "\n";
    }
}
