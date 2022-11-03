/**
 *    author:  MaGnsi0
 *    created: 18.06.2022 19:26:19
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353, HALF = 499122177;

template <typename T>
struct segment_tree {
    int N;
    T E;
    vector<T> S;
    function<T(T, T)> F;
    segment_tree(int n, T e, function<T(T, T)> f) : N(n), E(e), S(2 * n, e), F(f) {}
    void update(int j, T x) {
        for (S[j += N] = x; j /= 2;) {
            S[j] = F(S[2 * j], S[2 * j + 1]);
        }
    }
    T query(int L, int R) {
        T l = E, r = E;
        for (L += N, R += N; L < R; L /= 2, R /= 2) {
            if (L % 2) {
                l = F(l, S[L++]);
            }
            if (R % 2) {
                r = F(S[--R], r);
            }
        }
        return F(l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<int64_t> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    function<int64_t(int64_t, int64_t)> F = [&](int64_t L, int64_t R) {
        return (L + R) % MOD;
    };
    vector<segment_tree<int64_t>> S(3, segment_tree<int64_t>(N, 0, F));
    for (int i = 0; i < N; ++i) {
        S[0].update(i, A[i] % MOD);
        S[1].update(i, A[i] * i % MOD);
        S[2].update(i, A[i] * i % MOD * i % MOD);
    }
    for (int i = 0; i < Q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            int64_t v;
            cin >> x >> v;
            x--;
            S[0].update(x, v % MOD);
            S[1].update(x, v * x % MOD);
            S[2].update(x, v * x % MOD * x % MOD);
        } else {
            int x;
            cin >> x;
            x--;
            int64_t ans = 0;
            ans += S[0].query(0, x + 1) * (x + 1) % MOD * (x + 2) % MOD;
            ans += MOD - S[1].query(0, x + 1) * (2 * x + 3) % MOD;
            ans += S[2].query(0, x + 1) % MOD;
            ans *= HALF;
            ans %= MOD;
            cout << ans << "\n";
        }
    }
}
