/**
 *    author:  MaGnsi0
 *    created: 27.07.2023 06:17:27
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
        vector<vector<int>> a(m, vector<int>(26));
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            for (int j = 0; j < m; ++j) {
                a[j][s[j] - 'a']++;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            ans += *max_element(a[i].begin(), a[i].end());
        }
        cout << ans << "\n";
    }
}
