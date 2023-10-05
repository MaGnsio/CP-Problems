/**
 *    author:  MaGnsi0
 *    created: 16.06.2022 16:35:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        vector<set<int>> a(2);
        for (int i = 0; i < n; ++i) {
            a[s[i] - '0'].insert(i);
        }
        vector<int64_t> ans(n, -1);
        function<int64_t(int)> dfs = [&](int j) {
            if (ans[j] != -1) {
                return ans[j];
            }
            ans[j] = 0;
            auto it = a[(s[j] - '0') ^ 1].lower_bound(j);
            if (it != a[(s[j] - '0') ^ 1].end()) {
                ans[j] += (dfs(*it) + 1);
            }
            return ans[j];
        };
        int64_t res = n;
        for (int i = 0; i < n; ++i) {
            res += dfs(i);
        }
        cout << res << "\n";
    }
}
