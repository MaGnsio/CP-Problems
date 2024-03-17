/**
 *    author:  MaGnsi0
 *    created: 31.01.2024 22:35:16
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t K = 67, MOD = 1e9 + 7;

template<class T, int N>
struct Matrix {
    typedef Matrix M;
    int64_t MOD;
    array<array<T, N>, N> d{};
    Matrix(int64_t mod) : MOD(mod){}
    M operator*(const M& m) const {
        M a(MOD);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    a.d[i][j] += d[i][k] * m.d[k][j];
                    a.d[i][j] %= MOD;
                }
            }
        }
        return a;
    }
    vector<T> operator*(const vector<T>& vec) const {
        vector<T> ret(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                ret[i] += d[i][j] * vec[j];
                ret[i] %= MOD;
            }
        }
        return ret;
    }
    M operator^(int64_t p) const {
        assert(p >= 0);
        M a(MOD), b(*this);
        for (int i = 0; i < N; ++i) { a.d[i][i] = 1; }
        while (p) {
            if (p & 1) { a = a * b; }
            b = b * b;
            p >>= 1;
        }
        return a;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k; cin >> k;
    int64_t n; cin >> n; n++;
    Matrix<int64_t, K> B(MOD);
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (__gcd(i, j) != 1) { continue; }
            B.d[i][j] = 1;
        }
    }
    B = (B^n);
    cout << B.d[1][1];
}
