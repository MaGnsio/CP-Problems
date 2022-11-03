/**
 *    author:  MaGnsi0
 *    created: 01.10.2022 14:08:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        cout << a[x - 1][y - 1] << "\n";
    }
}
