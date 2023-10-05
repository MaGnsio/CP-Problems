/**
 *    author:  MaGnsi0
 *    created: 04/09/2021 18:15:17
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, N = 1e5 + 5;
    cin >> n;
    vector<long long> f(N, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        f[x] += x;
    }
    vector<long long> dp(N, 0);
    dp[1] = f[1];
    for (int i = 2; i < N; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + f[i]); 
    }
    cout << dp[N - 1];
}
