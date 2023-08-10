/**
 *    author:  MaGnsi0
 *    created: 11.05.2023 10:42:42
**/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> F(int n) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    vector<vector<int>> ans;
    ans.push_back(p);
    for (int i = 1; i <= n; ++i) {
        sort(p.begin(), p.end());
        int j = i - 1;
        while (j < n - 1) {
            swap(p[j], p[j + 1]);
            ans.push_back(p);
            j++;
        }
        sort(p.begin(), p.end());
        int k = i - 1;
        while (k > 0) {
            swap(p[k], p[k - 1]);
            ans.push_back(p);
            k--;
        }
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k, MOD;
        cin >> n >> k >> MOD;
        vector<vector<int>> a = F(n);
        int m = (int)a.size();
        if (k == 0) {
            cout << m % MOD << "\n";
            continue;
        }
        vector<int> b(k), c(k);
        for (int i = 0; i < k; ++i) {
            cin >> b[i] >> c[i];
            b[i]--, c[i]--;
        }
        reverse(b.begin(), b.end());
        reverse(c.begin(), c.end());
        int ans = 0;
        function<int(int, int)> solve = [&](int x, int y) {
            if (y == k) {
                return 1;
            }
            if (a[x][b[y]] > a[x][c[y]]) {
                return 0;
            }
            int res = 0;
            res += solve(x, y + 1);
            res %= MOD;
            swap(a[x][b[y]], a[x][c[y]]);
            res += solve(x, y + 1);
            res %= MOD;
            swap(a[x][b[y]], a[x][c[y]]);
            return res;
        };
        for (int i = 0; i < m; ++i) {
            ans += solve(i, 0);
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
