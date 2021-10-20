/**
 *    author:  MaGnsi0
 *    created: 20/09/2021 01:04:26
**/
#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;
int dp[160][150][60];

int solve(int i, int k, int l) {
    int& res = dp[i][k][l];
    if (res != -1) {
        return res;
    }
    if (i == 0) {
        return res = 0;
    }
    res = INT_MAX;
    int j = (a + 5 * b + 10 * c) - (8 * (n - i) + 5 * k + 10 * l);
    if (j >= 8) {
        res = min(res, 8 + solve(i - 1, k, l));
    }
    if (j >= 3 && k >= 1) {
        res = min(res, 4 + solve(i - 1, k - 1, l));
    }
    if (j >= 3 && l >= 1) {
        res = min(res, 4 + solve(i - 1, k + 1, l - 1));
    }
    if (k >= 2) {
        res = min(res, 2 + solve(i - 1, k - 2, l));
    }
    if (l >= 1) {
        res = min(res, 1 + solve(i - 1, k, l - 1));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> a >> b >> c;
        memset(dp, -1, sizeof dp);
        cout << solve(n, b, c) << "\n";
    }
}
