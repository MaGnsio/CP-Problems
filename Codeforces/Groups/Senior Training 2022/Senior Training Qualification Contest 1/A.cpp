/**
 *    author:  MaGnsi0
 *    created: 31.03.2022 01:04:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("subarrays.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k + 1, vector<long long>(2, -1)));
    function<long long(int, int, int)> solve = [&](int x, int y, int z) {
        if (x == n) {
            return 0LL;
        }
        long long& ans = dp[x][y][z];
        if (ans != -1) {
            return ans;
        }
        ans = max(0LL, a[x] + solve(x + 1, y, 0));
        if (z) {
            ans = max(ans, -a[x] + solve(x + 1, y, 1));
        } else if (y < k) {
            ans = max(ans, -a[x] + solve(x + 1, y + 1, 1));
        }
        return ans;
    };
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, solve(i, 0, 0));
    }
    cout << ans;
}
