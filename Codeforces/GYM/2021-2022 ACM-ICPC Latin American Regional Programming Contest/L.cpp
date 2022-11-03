/**
 *    author:  MaGnsi0
 *    created: 27.07.2022 08:12:11
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 2e6 + 6, MOD = 1e9 + 7;

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
    if (k == 0) {
        return 1;
    }
    if  (k > n) {
        return 0;
    }
    return (f[n] * inv_f[k] % m * inv_f[n - k] % m) % m;
}

template <typename T>
T P_mod(T n, T k, T m) {
    if (k > n) {
        return 0;
    }
    return (f[n] * inv_f[n - k]) % m;
}

template <typename T>
vector<T> power_two(int64_t MOD) {
    vector<T> P(N, 1);
    for (int i = 1; i < N; ++i) {
        P[i] = 2 * P[i - 1];
        P[i] %= MOD;
    }
    return P;
}

vector<int64_t> P2 = power_two<int64_t>(MOD);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t N, G, I, E;
    cin >> N >> G >> I >> E;
    if (G >= 2 * N) {
        G = 2 * N; 
        E = I = 0;
    }
    if (E >= 2 * N - G) {
        E = 2 * N - G;
        I = 0;
    }
    if (I >= 2 * N - G - E) {
        I = 2 * N - G - E;
    }
    int64_t ans = 0, totalP = power<int64_t>(P_mod<int64_t>(2 * N, G, MOD), MOD - 2, MOD);
    for (int64_t X = 0; 2 * X <= G; ++X) {
        int Y = G - 2 * X;
        int64_t P = C_mod<int64_t>(N, X, MOD);
        P %= MOD;
        P *= C_mod<int64_t>(G, 2 * X, MOD);
        P %= MOD;
        P *= P_mod<int64_t>(2 * X, 2 * X, MOD);
        P %= MOD;
        P *= P_mod<int64_t>(N - X, G - 2 * X, MOD);
        P %= MOD;
        P *= P2[G - 2 * X];
        P %= MOD;
        P *= totalP;
        P %= MOD;
        int64_t H = G;
        if (E >= Y) {
            H += Y;
            H += 2 * ((E - Y) / 2);
            int64_t remianO = (E - Y) % 2; 
            int64_t remianT = N - (X + Y + (E - Y) / 2 + remianO);
            if (I <= remianT) {
                H += I;
            } else {
                H += remianT;
                int64_t rI = I - remianT;
                if (rI >= remianO) {
                    H += remianO;
                    rI -= remianO;
                } else {
                    H += rI;
                    rI -= rI;
                }
                H -= rI;
            }
        } else {
            H += E;
            int64_t remianO = Y - E;
            int64_t remianT = N - (X + Y);
            if (I <= remianT) {
                H += I;
            } else {
                H += remianT;
                int64_t rI = I - remianT;
                if (rI >= remianO) {
                    rI -= remianO;
                } else {
                    rI -= rI;
                }
                H -= rI;
            }
        }
        ans += P * H;
        ans %= MOD;
    }
    cout << ans;
}
