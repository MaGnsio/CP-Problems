/**
 *    author:  MaGnsi0
 *    created: 15.08.2022 05:25:41
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

template <typename T, int N, T MOD>
struct matrix {
    array<array<T, N>, N> A{};
    matrix operator*(const matrix& b) const {
        matrix c;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    c.A[i][j] += A[i][k] * b.A[k][j];
                    c.A[i][j] %= MOD;
                }
            }
        }
        return c;
    }
};

template <typename P, typename T>
P power(P b, T p) {
    P res;
    for (int i = 0; i < (int)res.A.size(); ++i) {
        res.A[i][i] = 1;
    }
    while (p) {
        if (p & 1) {
            res = res * b;
        }
        b = b * b;
        p >>= 1;
    }
    return res;
}

using M = matrix<int64_t, 2, MOD>;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n;
    cin >> n;
    M ans;
    ans.A[0][0] = 19, ans.A[0][1] = 7;
    ans.A[1][0] = 6, ans.A[1][1] = 20;
    ans = power<M, int64_t>(ans, n);
    cout << ans.A[0][0];
}
