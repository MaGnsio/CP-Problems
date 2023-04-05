/**
 *    author:  MaGnsi0
 *    created: 14.03.2023 00:08:38
**/
#include <bits/stdc++.h>

using namespace std;

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
    int64_t A, X, M;
    cin >> A >> X >> M;
    Matrix<int64_t, 2> B(M);
    B.d[0][0] = A, B.d[0][1] = 1;
    B.d[1][0] = 0, B.d[1][1] = 1;
    B = B ^ X;
    cout << B.d[0][1];
}
