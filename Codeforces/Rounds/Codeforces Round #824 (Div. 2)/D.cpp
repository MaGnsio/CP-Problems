/**
 *    author:  MaGnsi0
 *    created: 03.10.2022 16:22:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    set<vector<int>> s;
    for (int i = 0; i < n; ++i) {
        s.insert(a[i]);
    }
    map<vector<int>, int64_t> mp;
    for (int i = 0; i < n; ++i) {
        s.erase(a[i]);
        for (int j = i + 1; j < n; ++j) {
            s.erase(a[j]);
            vector<int> b(m);
            for (int k = 0; k < m; ++k) {
                if (a[i][k] == a[j][k]) { b[k] = a[i][k]; }
                else {
                    if (a[i][k] != 0 && a[j][k] != 0) { b[k] = 0; } 
                    if (a[i][k] != 1 && a[j][k] != 1) { b[k] = 1; }
                    if (a[i][k] != 2 && a[j][k] != 2) { b[k] = 2; }
                }
            }
            mp[a[i]] += s.count(b);
            mp[a[j]] += s.count(b);
            mp[b] += s.count(b);
        }
        for (int j = i + 1; j < n; ++j) {
            s.insert(a[j]);
        }
    }
    int64_t ans = 0;
    for (auto& [x, y] : mp) {
        ans += y * (y - 1) / 2;
    }
    cout << ans;
}
