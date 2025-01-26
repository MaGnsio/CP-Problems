/**
 *    author:  MaGnsi0
 *    created: 26.01.2025 22:04:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<pair<vector<int>, int>> a(n);
        for (int i = 0; i < n; ++i) {
            a[i].first.resize(m);
            a[i].second = i;
            for (int j = 0; j < m; ++j) {
                cin >> a[i].first[j];
            }
            sort(a[i].first.begin(), a[i].first.end());
        }
        sort(a.begin(), a.end());
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            p[i] = a[i].second;
        }
        bool ok = true;
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                ok = ok && a[i].first[j] == j * n + i;
            }
        }
        if (!ok) {
            cout << -1 << "\n";
        } else {
            for (int i = 0; i < n; ++i) {
                cout << p[i] + 1 << (i == n - 1 ? "\n" : " ");
            }
        }
    }
}
