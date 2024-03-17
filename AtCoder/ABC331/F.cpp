/**
 *    author:  MaGnsi0
 *    created: 02.12.2023 14:22:35
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e6 + 6;
const int64_t P[2] = {31, 53};
const int64_t MOD[2] = {int64_t(1e9) + 7, int64_t(1e9) + 9};

vector<vector<int64_t>> power(2, vector<int64_t>(N));

struct H {
    int S;
    array<int64_t, 2> V;
    H() {
        S = V[0] = V[1] = 0;
    }
};

H F(H L, H R) {
    H res;
    res.S = L.S + R.S;
    for (int j = 0; j < 2; ++j) {
        res.V[j] = (L.V[j] + power[j][L.S] * R.V[j]) % MOD[j];
    }
    return res;
}

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
    power[0][0] = power[1][0] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 2; ++j) {
            power[j][i] = power[j][i - 1] * P[j] % MOD[j];
        }
    }
    int n; cin >> n;
    int Q; cin >> Q;
    string s; cin >> s;
    segment_tree<H> prefix(n, H(), [&](H L, H R) { return F(L, R); });
    segment_tree<H> suffix(n, H(), [&](H L, H R) { return F(R, L); });
    for (int i = 0; i < n; ++i) {
        H h;
        h.S = 1;
        for (int j = 0; j < 2; ++j) {
            h.V[j] = (s[i] - 'a') % MOD[j];
        }
        prefix.update(i, h);
        suffix.update(i, h);
    }
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int i; cin >> i; i--;
            char c; cin >> c;
            H h;
            h.S = 1;
            for (int j = 0; j < 2; ++j) {
                h.V[j] = (c - 'a') % MOD[j];
            }
            prefix.update(i, h);
            suffix.update(i, h);
        } else {
            int low; cin >> low; low--;
            int high; cin >> high; high--;
            H p = prefix.query(low, high + 1);
            H s = suffix.query(low, high + 1);
            cout << (p.V == s.V ? "Yes" : "No") << "\n";
        }
    }
}
