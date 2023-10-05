/**
 *    author:  MaGnsi0
 *    created: 13.09.2023 17:09:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> a(n, vector<pair<int, int>>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j].first;
            a[i][j].second = (i == j ? 0 : -1);
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = a[i][k].first + a[k][j].first;
                int y = a[i][k].second + a[k][j].second;
                if (x < a[i][j].first) {
                    cout << -1;
                    return 0;
                }
                a[i][j] = min(a[i][j], make_pair(x, y));
            }
        }
    }
    int X = INT_MAX, Y = INT_MAX, ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) { continue; }
            if (a[i][j].second != -1) {
                ans++;
            }
        }
    }
    cout << ans / 2;
}
