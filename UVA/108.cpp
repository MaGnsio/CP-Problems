/**
 *    author:  MaGnsi0
 *    created: 20/09/2021 14:50:02
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            v[i][j] += v[i][j - 1];
        }
    }
    int res = v[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int cur = 0;
            for (int k = 0; k < n; ++k) {
                cur += (v[k][j] - (i ? v[k][i - 1] : 0));
                res = max(cur, res);
                cur = max(cur, 0);
            }
        }
    }
    cout << res << endl;
}
