/**
 *    author:  MaGnsi0
 *    created: 26.11.2021 13:02:29
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 5;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> f(N);
    for (int i = 0; i < n; ++i) {
        f[a[i]]++;
    }
    vector<int> cnt(N);
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            cnt[i] += f[j];
        }
    }
    long long res = 0;
    vector<long long> dp(N, 0);
    for (int i = N - 1; i > 0; --i) {
        dp[i] = (long long)i * cnt[i];
        for (int j = 2 * i; j < N; j += i) {
            dp[i] = max(dp[i], dp[j] + (long long)i * (cnt[i] - cnt[j]));
        }
        res = max(res, dp[i]);
    }
    cout << res;
}
