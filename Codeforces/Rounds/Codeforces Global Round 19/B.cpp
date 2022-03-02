/**
 *    author:  MaGnsi0
 *    created: 12.02.2022 16:29:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> mex(n, vector<int>(n, -1));
        auto f = [](vector<int> a) {
            sort(a.begin(), a.end());
            for (int i = 0; i < (int)a.size(); ++i) {
                if (a[i] != i) {
                    return i;
                }
            }
            return (int)a.size();
        };
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = i; j < n; ++j) {
                temp.push_back(a[j]);
                mex[i][j] = f(temp);
            }
        }
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        function<long long(int, int)> solve = [&](int x, int y) {
            if (x == y) {
                return dp[x][y] = 1LL + (a[x] ? 0LL : 1LL);
            }
            if (dp[x][y] != -1) {
                return dp[x][y];
            }
            dp[x][y] = 1 + mex[x][y];
            for (int i = x; i < y; ++i) {
                dp[x][y] = max(dp[x][y], 1 + mex[x][i] + solve(i + 1, y));
            }
            return dp[x][y];
        };
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                res += solve(i, j);
            }
        }
        cout << res << "\n";
    }
}
