/**
 *    author:  MaGnsi0
 *    created: 12.11.2022 22:17:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int64_t>> s(1, vector<int64_t>(1, a[0]));
        for (int i = 1; i < n; ++i) {
            if (a[i] == 0) {
                s.push_back(vector<int64_t>(1, 0));
            } else {
                s.back().push_back(s.back().back() + a[i]);
            }
        }
        int ans = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            int m = (int)s[i].size();
            map<int64_t, int> mp;
            for (int j = 0; j < m; ++j) {
                mp[s[i][j]]++;
            }
            int maxo = 0;
            for (auto& [_, x] : mp) {
                maxo = max(maxo, x);
            }
            ans += (s[i][0] == 0 ? maxo : mp[0]);
        }
        cout << ans << "\n";
    }
}
