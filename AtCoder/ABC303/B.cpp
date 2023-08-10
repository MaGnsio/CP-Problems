/**
 *    author:  MaGnsi0
 *    created: 27.05.2023 15:03:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    vector<vector<bool>> b(n, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            b[a[i][j]][a[i][j - 1]] = b[a[i][j - 1]][a[i][j]] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            ans += b[i][j] == false;
        }
    }
    cout << ans;
}
