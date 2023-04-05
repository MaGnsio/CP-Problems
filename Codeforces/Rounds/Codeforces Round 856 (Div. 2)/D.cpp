/**
 *    author:  MaGnsi0
 *    created: 04.03.2023 20:06:01
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e4 + 4, M = 1e6 + 6, MOD = 998244353;

vector<bool> is_prime(M, true);
vector<int64_t> F(N), inv_F(N);

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return res;
}

int64_t C(int n, int k) {
    if (k > n) { return 0; }
    return F[n] * inv_F[k] % MOD * inv_F[n - k] % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < M; ++i) {
        if (is_prime[i]) {
            for (int j = 2 * i; j < M; j += i) {
                is_prime[j] = false;
            }
        }
    }
    F[0] = 1;
    for (int64_t i = 1; i < N; ++i) {
        F[i] = i * F[i - 1];
        F[i] %= MOD;
    }
    inv_F[N - 1] = power(F[N - 1], MOD - 2);
    for (int64_t i = N - 2; i >= 0; --i) {
        inv_F[i] = (i + 1) * inv_F[i + 1];
        inv_F[i] %= MOD;
    }
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }
    set<int> primes;
    for (int i = 0; i < 2 * n; ++i) {
        if (is_prime[a[i]]) { primes.insert(a[i]); }
    }
    vector<int> cnt(M, 0);
    for (int i = 0; i < 2 * n; ++i) {
        cnt[a[i]]++;
    }
    int64_t m = (int)primes.size();
    if (m < n) {
        cout << 0;
        return 0;
    }
    int64_t val = 1, x = n;
    val %= MOD;
    for (int i = 0; i < M; ++i) {
        if (is_prime[i] == false) {
            val *= C(x, cnt[i]);
            val %= MOD;
            x -= cnt[i];
        }
    }
    vector<int> b(primes.begin(), primes.end());
    vector<int> c(m);
    c[0] = cnt[b[0]];
    for (int i = 1; i < m; ++i) {
        c[i] = c[i - 1] + cnt[b[i]];
    }
    vector<vector<int64_t>> dp(m, vector<int64_t>(n + 1, -1));
    function<int64_t(int, int)> solve = [&](int i, int j) {
        if (i == m) { return int64_t(1); }
        if (dp[i][j] != -1) { return dp[i][j]; }
        dp[i][j] = 0;
        int unique = j;
        int not_unique = x - ((i ? c[i - 1] : 0) - (n - j));
        if (unique) {
            dp[i][j] += C(not_unique, cnt[b[i]] - 1) * solve(i + 1, j - 1);
            dp[i][j] %= MOD;
        }
        if (not_unique >= cnt[b[i]]) {
            dp[i][j] += C(not_unique, cnt[b[i]]) * solve(i + 1, j);
            dp[i][j] %= MOD;
        }
        return dp[i][j];
    };
    int64_t ans = solve(0, n);
    ans *= val;
    ans %= MOD;
    cout << ans;
}
