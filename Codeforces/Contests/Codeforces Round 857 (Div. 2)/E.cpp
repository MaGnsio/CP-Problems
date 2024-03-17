/**
 *    author:  MaGnsi0
 *    created: 03.01.2024 00:22:19
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> useful(vector<int> a) {
    vector<int> useful_a;
    useful_a.push_back(a[0]);
    for (int x : a) {
        if (x > useful_a.back()) {
            useful_a.push_back(x);
        }
    }
    return useful_a;
}

int compress(vector<vector<int>>& a) {
    set<int> all;
    for (vector<int> v : a) {
        for (int x : v) {
            all.insert(x);
        }
    }
    int m = (int)all.size();
    map<int, int> mp;
    for (int x : all) {
        mp[x] = (int)mp.size();
    }
    for (vector<int>& v : a) {
        for (int& x : v) {
            x = mp[x];
        }
    }
    return m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<vector<int>> a(n);
        for (int i = 0; i < n; ++i) {
            int m; cin >> m;
            a[i].resize(m);
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
            a[i] = useful(a[i]);
        }
        int m = compress(a);
        vector<vector<int>> adj(m);
        for (int i = 0; i < n; ++i) {
            for (int x : a[i]) {
                adj[x].push_back(i);
            }
        }
        vector<int> dp(m, -1);
        function<int(int)> solve = [&](int x) {
            if (x == m) { return 0; }
            if (dp[x] != -1) { return dp[x]; }
            dp[x] = solve(x + 1);
            for (int j : adj[x]) {
                int add = a[j].end() - lower_bound(a[j].begin(), a[j].end(), x);
                dp[x] = max(dp[x], solve(a[j].back() + 1) + add);
            }
            return dp[x];
        };
        int ans = solve(0);
        cout << ans << "\n";
    }
}
