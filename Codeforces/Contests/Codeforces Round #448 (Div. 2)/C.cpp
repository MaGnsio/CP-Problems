/**
 *    author:  MaGnsi0
 *    created: 15.03.2023 03:08:42
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 75;
const int64_t MOD = 1e9 + 7;
vector<int> masks(N), primes;

int F(int x) {
    int mask = 0;
    for (int j = 0; j < (int)primes.size(); ++j) {
        int y = 0;
        while (x % primes[j] == 0) {
            x /= primes[j];
            y++;
        }
        if (y & 1) {
            mask |= (1 << j);
        }
    }
    return mask;
}

int64_t power(int64_t b, int64_t p) {
    int ans = 1;
    while (p) {
        if (p & 1) {
            ans = ans * b % MOD;
        }
        b = b * b % MOD;
        p /= 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 2; i < N; ++i) {
        bool is_prime = true;
        for (int j = 2; j < i; ++j) {
            is_prime &= i % j != 0;
        }
        if (is_prime) {
            primes.push_back(i);
        }
    }
    for (int i = 1; i < N; ++i) {
        masks[i] = F(i);
    }
    int n, m = (int)primes.size();
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        mp[a[i]]++;
    }
    vector<int64_t> b(N), c(N);
    for (int i = 0; i < N; ++i) {
        if (mp.count(i)) {
            b[i] = c[i] = power(2, mp[i] - 1);
        } else {
            b[i] = 1, c[i] = 0;
        }
    }
    int k = 0;
    vector<vector<int64_t>> dp(2, vector<int64_t>((1 << m), 0));
    dp[0][0] = 1;
    for (int i = 0; i + 1 < N; ++i) {
        for (int j = 0; j < (1 << m); ++j) {
            dp[k ^ 1][j ^ masks[i + 1]] += dp[k][j] * c[i + 1] % MOD;
            dp[k ^ 1][j ^ masks[i + 1]] %= MOD;
            dp[k ^ 1][j] += dp[k][j] * b[i + 1] % MOD;
            dp[k ^ 1][j] %= MOD;
        }
        k ^= 1;
        dp[k ^ 1] = vector<int64_t>((1 << m), 0);
    }
    int64_t ans = (dp[k][0] + MOD - 1) % MOD;
    cout << ans;
}
