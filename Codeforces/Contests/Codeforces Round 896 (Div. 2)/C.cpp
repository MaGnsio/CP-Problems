/**
 *    author:  MaGnsi0
 *    created: 10.09.2023 17:55:11
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
        vector<int> p(m);
        iota(p.begin(), p.end(), 0);
        vector<vector<int>> a(n, vector<int>(m, 0));
        for (int i = 0; i < min(n, m - 1); ++i) {
            int k = i;
            for (int j = 0; j < m; ++j) {
                a[i][j] = p[k];
                k = (k + 1) % m;
            }
        }
        for (int i = min(n, m - 1); i < n; ++i) {
            a[i] = p;
        }
        vector<int> mexs(m, 0);
        for (int j = 0; j < m; ++j) {
            map<int, int> cnt;
            for (int i = 0; i < n; ++i) {
                cnt[a[i][j]]++;
            }
            for (auto [x, _] : cnt) {
                if (x != mexs[j]) {
                    break;
                }
                mexs[j]++;
            }
        }
        map<int, int> cnt;
        for (int i = 0; i < m; ++i) {
            cnt[mexs[i]]++;
        }
        int ans = 0;
        for (auto [x, _] : cnt) {
            if (x != ans) {
                break;
            }
            ans++;
        }
        cout << ans << "\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
