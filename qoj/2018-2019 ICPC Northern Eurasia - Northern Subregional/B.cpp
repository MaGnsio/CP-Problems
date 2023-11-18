/**
 *    author:  MaGnsi0
 *    created: 28.09.2023 23:46:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\no\n";
        return 0;
    }
    if (n == 2) {
        cout << "-1\n";
        return 0;
    }
    int m = (n + 1) / 2;
    vector<vector<char>> ans(m, vector<char>(m, '.'));
    for (int i = 0; i < m; ++i) {
        ans[i][0] = 'o';
        ans[m - 1][i] = 'o';
    }
    if (n % 2 == 0) {
        ans[m - 2][1] = 'o';
    }
    cout << m << "\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
}
