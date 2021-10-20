/**
 *    author:  MaGnsi0
 *    created: 11/09/2021 20:15:22
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    freopen("traffic_control_input.txt", "r", stdin);
    freopen("traffic_control_output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        cout << "Case #" << tc << ": ";
        if (n + m - 1 > a || n + m - 1 > b) {
            cout << "Impossible\n";
            continue;
        }
        vector<vector<int>> v(n, vector<int>(m, 1000));
        for (int i = 0; i < n; ++i) {
            v[i][m - 1] = 1;
            a--, b--;
        }
        for (int i = m - 2; i >= 0; --i) {
            v[0][i] = 1;
            a--;
            if (!i) {
                v[0][i] += a;
            }
        }
        for (int i = m - 2; i >= 0; --i) {
            v[n - 1][i] = 1;
            b--;
            if (!i) {
                v[n - 1][i] += b;
            }
        }
        cout << "Possible\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
