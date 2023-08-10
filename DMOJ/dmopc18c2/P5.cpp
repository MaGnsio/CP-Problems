/**
 *    author:  MaGnsi0
 *    created: 18.07.2023 17:08:53
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m, k;
    int64_t n;
    cin >> n >> m >> k;
    vector<int> a(m + 1);
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        a[x]++;
    }
    function<vector<int>(vector<int>, vector<int>)> F = [&](vector<int> b, vector<int> c) {
        vector<int> ans(m + 1);
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= i; ++j) {
                ans[i] += int64_t(b[j]) * c[i - j] % MOD;
                ans[i] %= MOD;
            }
        }
        return ans;
    };
    function<vector<int>(int64_t)> solve = [&](int64_t x) {
        if (x == 1) {
            return a;
        }
        vector<int> res = solve(x / 2);
        if (x & 1) {
            return F(F(res, res), a);
        } else {
            return F(res, res);
        }
    };
    int res = 0;
    vector<int> ans = solve(n);
    for (int64_t x : ans) {
        res += x;
        res %= MOD;
    }
    cout << res;
}
