/**
 *    author:  MaGnsi0
 *    created: 10.08.2024 16:17:16
**/
#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 51;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n), b(n), I(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i]; I[i] = i;
    }
    sort(I.begin(), I.end(), [&](int i, int j) {
            return (a[i] - 1) * b[j] > (a[j] - 1) * b[i];
        });
    vector<vector<int64_t>> dp(n, vector<int64_t>(k + 1, -1));
    function<int64_t(int, int)> solve = [&](int x, int y) {
        if (y == 0 || x == n) { return int64_t(1); }
        if (dp[x][y] != -1) { return dp[x][y]; }
        dp[x][y] = solve(x + 1, y);
        dp[x][y] = max(solve(x + 1, y), a[I[x]] * solve(x + 1, y - 1) + b[I[x]]);
        return dp[x][y];
    };
    cout << solve(0, k);
}
