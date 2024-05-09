/**
 *    author:  MaGnsi0
 *    created: 10.05.2024 00:16:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            a[i][j] *= a[i][j];
            a[i][j] *= a[i][j];
        }
    }
    int base = 1;
    for (int i = 1; i <= 16; ++i) {
        base = base * i / __gcd(base, i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << base + ((i + j) & 1) * a[i][j] << " ";
        }
        cout << "\n";
    }
}
