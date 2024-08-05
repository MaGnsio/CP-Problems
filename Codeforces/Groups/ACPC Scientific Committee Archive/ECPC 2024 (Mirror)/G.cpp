/**
 *    author:  MaGnsi0
 *    created: 29.07.2024 17:02:03
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e6, MOD = 1e9 + 7;

vector<int64_t> F(N, 1), F_(N , 1);

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return res;
}

void __init__() {
    for (int i = 1; i < N; ++i) {
        F[i] = F[i - 1] * i % MOD;
        F_[i] = power(F[i], MOD - 2);
    }
}

int64_t C(int n, int k) {
    if (k > n) { return 0; }
    return F[n] * F_[k] % MOD * F_[n - k] % MOD;
}

void fft(vector<complex<double>>& a) {
    int n = (int)a.size(), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<complex<double>> rt(2, 1);
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        for (int i = k; i < 2 * k; ++i) { rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2]; }
    }
    vector<int> rev(n);
    for (int i = 0; i < n; ++i) { rev[i] = (rev[i / 2] | (i & 1) << L) / 2; }
    for (int i = 0; i < n; ++i) { if (i < rev[i]) { swap(a[i], a[rev[i]]); } }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; ++j) {
                auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];
                complex<double> z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
        }
    }
}

vector<double> conv(const vector<double>& a, const vector<double>& b) {
    if (a.empty() || b.empty()) { return {}; }
    vector<double> res((int)a.size() + (int)b.size() - 1);
    int L = 32 - __builtin_clz((int)res.size()), n = 1 << L;
    vector<complex<double>> in(n), out(n);
    copy(a.begin(), a.end(), begin(in));
    for (int i = 0; i < (int)b.size(); ++i) { in[i].imag(b[i]); }
    fft(in);
    for (complex<double>& x : in) { x *= x; }
    for (int i = 0; i < n; ++i) { out[i] = in[-i & (n - 1)] - conj(in[i]); }
    fft(out);
    for (int i = 0; i < (int)res.size(); ++i) { res[i] = imag(out[i]) / (4 * n); }
    return res;
}

template<int64_t M>
vector<int64_t> convMod(const vector<int64_t> &a, const vector<int64_t> &b) {
    if (a.empty() || b.empty()) { return {}; }
    vector<int64_t> res((int)a.size() +  (int)b.size() - 1);
    int B = 32 - __builtin_clz((int)res.size()), n = 1 << B, cut = int(sqrt(M));
    vector<complex<double>> L(n), R(n), outs(n), outl(n);
    for (int i = 0; i < (int)a.size(); ++i) { L[i] = complex<double>((int)a[i] / cut, (int)a[i] % cut); }
    for (int i = 0; i < (int)b.size(); ++i) { R[i] = complex<double>((int)b[i] / cut, (int)b[i] % cut); }
    fft(L), fft(R);
    for (int i = 0; i < n; ++i) {
        int j = -i & (n - 1);
        outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
        outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
    }
    fft(outl), fft(outs);
    for (int i = 0; i < (int)res.size(); ++i) {
        int64_t av = int64_t(real(outl[i]) + 0.5), cv = int64_t(imag(outs[i]) + 0.5);
        int64_t bv = int64_t(imag(outl[i]) + 0.5) + int64_t(real(outs[i]) + 0.5);
        res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
    }
    return res;
}

struct Hash {
    const array<int64_t, 2> BASE = {31, 53};
    const array<int64_t, 2> MOD = {int64_t(1e9 + 7), int64_t(1e9 + 9)};
    
    int n; string s;
    vector<array<int64_t, 2>> prefix, P, P_;

    Hash(string s) {
        n = (int)s.size();
        this -> s = s;
        prefix.resize(n);
        P.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (i == 0) {
                    P[i][j] = 1;
                    continue;
                }
                P[i][j] = P[i - 1][j] * BASE[j] % MOD[j]; 
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (i == 0) {
                    prefix[i][j] = s[i] - 'a';
                } else {
                    prefix[i][j] = (prefix[i - 1][j] + P[i][j] * (s[i] - 'a') % MOD[j]) % MOD[j];
                }
            }
        }
    }

    array<int64_t, 2> insert(int i, char c) {
        assert(0 <= i && i <= n);
        array<int64_t, 2> res = {0, 0};
        for (int j = 0; j < 2; ++j) {
            res[j] += (i ? prefix[i - 1][j] : 0);
            res[j] += P[i][j] * (c - 'a') % MOD[j];
            res[j] %= MOD[j];
            res[j] += BASE[j] * (prefix[n - 1][j] - (i ? prefix[i - 1][j] : 0) + MOD[j]) % MOD[j];
            res[j] %= MOD[j];
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    __init__();
    string s; cin >> s;
    int n = (int)s.size();
    Hash H(s);
    set<string> test;
    map<array<int64_t, 2>, int> unique_s;
    for (int i = 0; i <= n; ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            unique_s[H.insert(i, c)]++;
        }
    }
    int64_t den = power(26 * (n + 1), MOD - 2);
    map<int, int64_t> unique_f;
    for (auto [_, f] : unique_s) {
        unique_f[f]++;
    }
    vector<int64_t> poly_all(1, 1);
    for (auto [f, m] : unique_f) {
        int64_t p = f * den % MOD, cur_p = 1;
        vector<int64_t> poly_f(m + 1);
        for (int pick = 0; pick <= m; ++pick) {
            poly_f[pick] = C(m, pick) * cur_p % MOD;
            cur_p = p * cur_p % MOD;
        }
        poly_all = convMod<MOD>(poly_all, poly_f);
    }
    int64_t ans = 0;
    for (auto [f, m] : unique_f) {
        int k = (int)poly_all.size();
        int64_t p = f * den % MOD;
        vector<int64_t> poly_x(k);
        poly_x[0] = poly_all[0];
        for (int i = 1; i < k; ++i) {
            poly_x[i] = (poly_all[i] - p * poly_x[i - 1] % MOD + MOD) % MOD;
        }
        int64_t val = 0;
        for (int t = 0; t < k - 1; ++t) {
            val += (t + 2) * p % MOD * p % MOD * poly_x[t] % MOD * F[t + 1] % MOD;
            val %= MOD;
        }
        ans = (ans + m * val % MOD) % MOD;
    }
    cout << ans;
}
