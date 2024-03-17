/**
 *    author:  MaGnsi0
 *    created: 26.11.2023 12:18:37
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 4, M = 22;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<bool> F(N); F[0] = true;
    for (int i = 0; i < n; ++i) {
        F[a[i]] = true;
    }
    vector<int> dp(N, -1);
    function<int(int)> solve = [&](int x) {
        if (F[x]) { return x; }
        if (dp[x] != -1) { return dp[x]; }
        dp[x] = 0;
        for (int b = 0; b < M; ++b) {
            if (x >> b & 1) {
                dp[x] = max(dp[x], solve(x ^ (1 << b)));
            }
        }
        return dp[x];
    };
    for (int i = 0; i < n; ++i) {
        int res = solve(a[i] ^ ((1 << M) - 1));
        cout << (res ? res : -1) << " ";
    }
}
