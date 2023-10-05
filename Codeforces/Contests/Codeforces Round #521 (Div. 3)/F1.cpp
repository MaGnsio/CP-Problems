/**
 *    author:  MaGnsi0
 *    created: 06.09.2022 21:47:41
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e14;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K, X;
    cin >> N >> K >> X;
    vector<int64_t> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    vector<vector<vector<int64_t>>> dp(N, vector<vector<int64_t>>(K, vector<int64_t>(X, -1)));
    function<int64_t(int, int, int)> solve = [&](int n, int k, int x) {
        if (X == x) {
            return (N - (n - k - 1) > K) * -OO;
        }
        if (N == n) {
            return int64_t(0);
        }
        int64_t& res = dp[n][k][x];
        if (res != -1) {
            return res;
        }
        res = a[n] + solve(n + 1, 0, x + 1);
        if (k + 1 < K) {
            res = max(res, solve(n + 1, k + 1, x));
        }
        return res;
    };
    int64_t ans = solve(0, 0, 0);
    cout << (ans < 0 ? -1 : ans);
}
