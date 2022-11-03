/**
 *    author:  MaGnsi0
 *    created: 02.08.2022 04:22:10
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 2e5 + 5, MOD = 998244353;

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

vector<int64_t> f = mod_factorials(N, MOD);

template <typename T>
vector<T> inverse_mod_factorials(T n, T m){
    vector<T> inv_f(n);
    for (T i = 0; i < n; ++i) {
        inv_f[i] = pmod_inverse(f[i], m);
    }
    return inv_f;
}

vector<int64_t> inv_f = inverse_mod_factorials(N, MOD);

template <typename T>
T C_mod(T n, T k, T m) {
    if (k > n) {
        return 0;
    }
    if (k == 0) {
        return 1;
    }
    return (f[n] * inv_f[k] % m * inv_f[n - k] % m) % m;
}

template <typename T>
T P_mod(T n, T k, T m) {
    return (f[n] * inv_f[n - k]) % m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cnt(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        cnt[u - 1]++;
        cnt[u - 1] %= 2;
        cnt[v - 1]++;
        cnt[v - 1] %= 2;
    }
    int even = count(cnt.begin(), cnt.end(), 0);
    int odd = count(cnt.begin(), cnt.end(), 1);
    int64_t ans = 0;
    for (int i = 0; i <= min(k, odd); i += 2) {
        ans += C_mod<int64_t>(odd, i, MOD) * C_mod<int64_t>(even, k - i, MOD) % MOD;
        ans %= MOD;
    }
    cout << ans;
}
