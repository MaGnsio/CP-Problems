/**
 *    author:  MaGnsi0
 *    created: 05.05.2023 19:10:35
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m, n;
    cin >> m >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int64_t>> b(n, vector<int64_t>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> b[j][i];
        }
    }
    vector<int> I(n);
    iota(I.begin(), I.end(), 0);
    vector<bitset<N>> c(n, 0);
    for (int i = 0; i < m; ++i) {
        sort(I.begin(), I.end(), [&](int x, int y) {
                return b[x][i] < b[y][i];
            });
        bitset<N> X(0);
        for (int j = 0; j < n; ++j) {
            int k = j;
            while (k < n && b[I[k]][i] == b[I[j]][i]) { k++; }
            for (int x = j; x < k; ++x) {
                X[I[x]] = 1;
            }
            for (int x = j; x < k; ++x) {
                c[I[x]] |= X;
            }
            j = k - 1;
        }
    }
    vector<int64_t> dp(n, -1);
    function<int64_t(int)> solve = [&](int j) {
        if (dp[j] != -1) {
            return dp[j];
        }
        dp[j] = a[j];
        for (int i = 0; i < n; ++i) {
            if (c[j][i] == 0) {
                dp[j] = max(dp[j], a[j] + solve(i));
            }
        }
        return dp[j];
    };
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, solve(i));
    }
    cout << ans;
}
