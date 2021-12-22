/**
 *    author:  MaGnsi0
 *    created: 05.11.2021 21:35:24
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e3 + 3, OO = 1e8;

int n, p, q;
int l = 1, r = 1e9, w = 1e9;

vector<int> a;

int solve(vector<vector<int>>& dp, vector<int>& jump1, vector<int>& jump2, int& m, int i, int j) {
    if (i == n) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int& ret = dp[i][j];
    ret = OO;
    if (j == 0) {
        ret = solve(dp, jump1, jump2, m, jump2[i], j) + 1;
    } else {
        ret = min(solve(dp, jump1, jump2, m, jump1[i], j - 1), solve(dp, jump1, jump2, m, jump2[i], j) + 1); 
    }
    return ret;
}

bool good(int m) {
    vector<vector<int>> dp(N, vector<int>(N, -1));
    vector<int> jump1(n), jump2(n);
    for (int i = 0; i < n; ++i) {
        jump1[i] = lower_bound(a.begin(), a.end(), a[i] + m) - a.begin();
        jump2[i] = lower_bound(a.begin(), a.end(), a[i] + 2 * m) - a.begin();
    }
    return (solve(dp, jump1, jump2, m, 0, p) <= q);
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> p >> q;
    p = min(p, 2000LL);
    a = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while (l <= r) {
        int m = (l + r) / 2;
        if (good(m)) {
            w = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << w;
}
