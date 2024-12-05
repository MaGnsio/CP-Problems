/**
 *    author:  MaGnsi0
 *    created: 06.12.2024 01:26:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string in;
    vector<string> a;
    while (cin >> in) {
        a.push_back("...." + in + "....");
    }
    int n = (int)a.size(), m = (int)a[0].size(), ans = 0;
    a.push_back(string(m, '.')); a.insert(a.begin(), string(m, '.'));
    a.push_back(string(m, '.')); a.insert(a.begin(), string(m, '.'));
    a.push_back(string(m, '.')); a.insert(a.begin(), string(m, '.'));
    a.push_back(string(m, '.')); a.insert(a.begin(), string(m, '.'));
    n += 8;
    for (int i = 4; i < n - 4; ++i) {
        for (int j = 4; j < m - 4; ++j) {
            ans += a[i][j] == 'M' && a[i][j + 2] == 'M' && a[i + 1][j + 1] == 'A' && a[i + 2][j] == 'S' && a[i + 2][j + 2] == 'S';
            ans += a[i][j] == 'M' && a[i][j + 2] == 'S' && a[i + 1][j + 1] == 'A' && a[i + 2][j] == 'M' && a[i + 2][j + 2] == 'S';
            ans += a[i][j] == 'S' && a[i][j + 2] == 'M' && a[i + 1][j + 1] == 'A' && a[i + 2][j] == 'S' && a[i + 2][j + 2] == 'M';
            ans += a[i][j] == 'S' && a[i][j + 2] == 'S' && a[i + 1][j + 1] == 'A' && a[i + 2][j] == 'M' && a[i + 2][j + 2] == 'M';
        }
    }
    cout << ans;
}

