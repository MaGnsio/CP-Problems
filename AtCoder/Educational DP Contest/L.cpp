/**
 *    author:  MaGnsi0
 *    created: 26/09/2021 20:06:22
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    vector<vector<long long>> dp(n, vector<long long>(n));
    for (int i = n - 1; i >= 0; --i) {
        dp[i][i] = a[i];
        for (int j = i + 1; j < n; ++j) {
            dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
        }
    }
    printf("%lld", dp[0][n - 1]);
}
