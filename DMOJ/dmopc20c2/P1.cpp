/**
 *    author:  MaGnsi0
 *    created: 14.04.2023 22:01:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<char>> ans(4 * n, vector<char>(n, '.'));
    int x = 2 * n, y = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '^') {
            ans[x][y] = '/';
            x--, y++;
        } else if (s[i] == 'v') {
            x++;
            ans[x][y] = '\\';
            y++;
        } else {
            ans[x][y] = '_';
            y++;
        }
    }
    for (int i = 0; i < 4 * n; ++i) {
        if (count(ans[i].begin(), ans[i].end(), '.') == n) {
            continue;
        }
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
}
