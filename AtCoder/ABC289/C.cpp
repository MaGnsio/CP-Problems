/**
 *    author:  MaGnsi0
 *    created: 11.02.2023 14:10:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<vector<int>> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        b[i].resize(a[i]);
        for (int j = 0; j < a[i]; ++j) {
            cin >> b[i][j];
        }
    }
    int ans = 0;
    for (int mask = 1; mask < (1 << m); ++mask) {
        set<int> s;
        for (int j = 0; j < m; ++j) {
            if ((mask >> j) & 1) {
                for (int k = 0; k < a[j]; ++k) {
                    s.insert(b[j][k]);
                }
            }
        }
        ans += (int)s.size() == n;
    }
    cout << ans;
}
