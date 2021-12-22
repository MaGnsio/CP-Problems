/**
 *    author:  MaGnsi0
 *    created: 31.10.2021 17:21:16
**/
#include <bits/stdc++.h>

using namespace std;

const long long N = 505, MOD = 998244353;
 
template <typename T>
T power(T b, T p, T m) {
    T res = 1;
    while (p) {
        if (p & 1) {
            res = ((res % m) * (b % m)) % m;
        }
        b = ((b % m) * (b % m)) % m;
        p >>= 1;
    }
    return res;
}

template <typename T>
T pmod_inverse(T n, T m) {
    return power(n, m - 2, m);
}

template <typename T>
vector<T> mod_factorials(T n, T m){
    vector<T> f(n);
    f[0] = 1;
    for (T i = 1; i < n; ++i) {
        f[i] = (f[i - 1] * i) % m;
    }
    return f;
}

vector<long long> f = mod_factorials(N, MOD);

template <typename T>
vector<T> inverse_mod_factorials(T n, T m){
    vector<T> inv_f(n);
    for (T i = 0; i < n; ++i) {
        inv_f[i] = pmod_inverse(f[i], m);
    }
    return inv_f;
}

vector<long long> inv_f = inverse_mod_factorials(N, MOD);

template <typename T>
T C_mod(T n, T k, T m) {
    if (k == 0 || n == k) {
        return 1;
    }
    return (f[n] * inv_f[k] % m * inv_f[n - k] % m) % m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, x;
    cin >> n >> x;
    vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));
    dp[n][0] = 1LL;
    for (long long i = n; i > 1; --i) {
        for (long long j = 0; j < x; ++j) {
            if (dp[i][j] == 0) {
                continue;
            }
            long long nj = min(x, j + i - 1);
            for (long long k = 0; k <= i; ++k) {
                dp[k][nj] += ((dp[i][j] % MOD * C_mod(i, i - k, MOD)) % MOD * power(nj - j, i - k, MOD)) % MOD;
            }
        }
    }
    long long res = 0;
    for (int i = 0; i <= x; ++i) {
        res += dp[0][i];
        res %= MOD;
    }
    cout << res;
}

/*
 * - dp[i][j]
 *   the number of ways to choose the initial health if there are i heroes still alive
 *   and they already received j damage.
 *
 * - Let's iterate over k (0 <= i <= k) "the number of heroes that will survive after the next round".
 *
 * - Then we have to make a transition to the state dp[k][nj]
 *   where nj=min(x,j+i−1) (the minimum of the maximum allowed health and j plus the damage done in this round).
 *
 * - It remains to understand with what coefficient we should make this transition in dynamic programming.
 *   This coefficient is equal to (i)Choose(i−k)*(nj−j)^(i−k) the number of ways to choose which of the i living heroes will die
 *   in this round multiplied by the number of ways to choose health for these i−k heroes
 *   (because their health is greater than j so that they are still alive at the moment,
 *   but not more than nj so that they are guaranteed to die in this round).
 *
 * - Of course, we don't make any transitions from the states dp[i][j] where i<2,
 *   since they represent the fights that have already finished.
 * 
 * - The answer is the sum of all dp[0][j] for every (0 <= j <= x).
 */
