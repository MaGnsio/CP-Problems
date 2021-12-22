/**
 *    author:  MaGnsi0
 *    created: 26.11.2021 13:02:30
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e7 + 7;

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
    vector<bool> isP(N, true);
    isP[0] = isP[1] = false;
    for (int i = 2; i < N; ++i) {
        if (isP[i]) {
            for (int j = 2 * i; j < N; j += i) {
                isP[j] = false;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        if (isP[i]) {
            for (int j = (N - 1) / i; j > 0; --j) {
                f[j] += f[i * j];
            }
        }
    }
    vector<int> p;
    for (int i = 0; i < N; ++i) {
        if (isP[i]) {
            p.push_back(i);
        }
    }
    vector<long long> dp(N);
    for (int i = N - 1; i > 0; --i) {
        dp[i] = (long long)i * f[i];
        for (int j : p) {
            if ((long long)i * j >= N) {
                break;
            }
            dp[i] = max(dp[i], dp[i * j] + (long long)i * (f[i] - f[i * j]));
        }
    }
    cout << dp[1];
}
