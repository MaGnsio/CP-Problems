/**
 *    author:  MaGnsi0
 *    created: 11/07/2021 21:28:32
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<long long, int>> v(n);
        for (auto& [x, y] : v) {
            cin >> y;
            y--;
        }
        for (auto& [x, y] : v) {
            cin >> x;
        }
        vector<long long> ans(n, 0);
        sort(v.begin(), v.end(), greater<pair<long long, int>>());
        vector<vector<long long>> pre(n);
        for (auto& [x, y] : v) {
            long long a = (pre[y].empty() ? 0LL : pre[y].back());
            pre[y].push_back(x + a);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= pre[i].size(); ++j) {
                ans[j - 1] += pre[i][(pre[i].size() / j) * j - 1];
            }
        }
        for (auto& x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
