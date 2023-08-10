/**
 *    author:  MaGnsi0
 *    created: 20.06.2023 16:19:56
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
        vector<vector<int>> a(n, vector<int>(4, -1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char x, y;
                cin >> x >> y;
                a[j][x - 'A'] = y == 'T';
            }
        }
        for (int i = 0; i < n; ++i) {
            if (count(a[i].begin(), a[i].end(), 1) == 0 && count(a[i].begin(), a[i].end(), 0) < 3) {
                cout << "?";
            } else if (count(a[i].begin(), a[i].end(), 1) == 1) {
                for (int j = 0; j < 4; ++j) {
                    if (a[i][j] == 1) {
                        cout << char('A' + j);
                        break;
                    }
                }
            } else {
                for (int j = 0; j < 4; ++j) {
                    if (a[i][j] != 0) {
                        cout << char('A' + j);
                        break;
                    }
                }
            }
            if (i != n - 1) { cout << " "; }
        }
        cout << "\n";
    }
}
