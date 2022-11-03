/**
 *    author:  MaGnsi0
 *    created: 15.08.2022 05:17:52
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T, int N>
struct matrix {
    array<array<T, N>, N> A{};
    matrix operator*(const matrix& b) const {
        matrix c;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    c.A[i][j] += A[i][k] * b.A[k][j];
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


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    double p;
    cin >> n >> p;
    matrix<double, 2> ans;
    ans.A[0][0] = 1 - p, ans.A[0][1] = p;
    ans.A[1][0] = p, ans.A[1][1] = 1 - p;
    ans = power<matrix<double, 2>, int>(ans, n); 
    cout << fixed << setprecision(9) << ans.A[0][0];
}
