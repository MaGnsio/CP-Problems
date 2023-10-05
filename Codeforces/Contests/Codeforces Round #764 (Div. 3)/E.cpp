/**
 *    author:  MaGnsi0
 *    created: 10.01.2022 16:35:35
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
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        string s;
        cin >> s;
        map<string, pair<int, pair<int, int>>> mp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j + 1 < m; ++j) {
                mp[a[i].substr(j, 2)] = {i + 1, {j + 1, j + 2}};
            }
            for (int j = 0; j + 2 < m; ++j) {
                mp[a[i].substr(j, 3)] = {i + 1, {j + 1, j + 3}};
            }
        }
        vector<int> dp(m, -1);
        function<int(int)> solve = [&](int x) {
            if (x == m) {
                return 1;
            }
            if (dp[x] != -1) {
                return dp[x];
            }
            dp[x] = 0;
            if (x + 1 < m) {
                if (mp.find(s.substr(x, 2)) != mp.end()) {
                    dp[x] = solve(x + 2);
                }
            }
            if (x + 2 < m) {
                if (mp.find(s.substr(x, 3)) != mp.end()) {
                    dp[x] = max(dp[x], solve(x + 3));
                }
            }
            return dp[x];
        };
        vector<pair<int, pair<int, int>>> res;
        function<void(int)> build_output = [&](int x) {
            if (x == m) {
                return;
            }
            if (x + 1 < m && solve(x + 2)) {
                res.push_back(mp[s.substr(x, 2)]);
                build_output(x + 2);
            } else {
                res.push_back(mp[s.substr(x, 3)]);
                build_output(x + 3);
            }
        };
        if (solve(0) == 0) {
            cout << "-1\n";
            continue;
        } else {
            build_output(0);
            cout << (int)res.size() << "\n";
            for (auto& [x, p] : res) {
                int y = p.first, z = p.second;
                cout << y << " " << z << " " << x << "\n";
            }
        }
    }
}
