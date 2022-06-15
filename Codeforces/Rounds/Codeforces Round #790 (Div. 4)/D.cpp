/**
 *    author:  MaGnsi0
 *    created: 11.05.2022 15:58:54
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
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        vector<vector<int>> s1(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                s1[i][j] = a[i][j] + (i && j ? s1[i - 1][j - 1] : 0);
            }
        }
        vector<vector<int>> s2(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = m - 1; j >= 0; --j) {
                s2[i][j] = a[i][j] + (i && j + 1 < m ? s2[i - 1][j + 1] : 0);
            }
        }
        vector<vector<int>> s3(n, vector<int>(m));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                s3[i][j] = a[i][j] + (i + 1 < n && j ? s3[i + 1][j - 1] : 0);
            }
        }
        vector<vector<int>> s4(n, vector<int>(m));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                s4[i][j] = a[i][j] + (i + 1 < n && j + 1 < m ? s4[i + 1][j + 1] : 0);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, s1[i][j] + s2[i][j] + s3[i][j] + s4[i][j] - 3 * a[i][j]);
            }
        }
        cout << ans << "\n";
    }
}
