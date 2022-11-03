/**
 *    author:  MaGnsi0
 *    created: 15.08.2022 05:50:55
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 65;

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

using M = matrix<unsigned int, N>;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n;
    cin >> n;
    M ans;
    for (int i1 = 0; i1 < 8; ++i1) {
        for (int j1 = 0; j1 < 8; ++j1) {
            for (int i2 = 0; i2 < 8; ++i2) {
                for (int j2 = 0; j2 < 8; ++j2) {
                    bool can_transit = false;
                    if ((i1 == i2 + 2) && (j1 == j2 + 1)) {
                        can_transit = true;
                    } else if ((i1 == i2 + 2) && (j1 == j2 - 1)) {
                        can_transit = true;
                    } else if ((i1 == i2 - 2) && (j1 == j2 + 1)) {
                        can_transit = true;
                    } else if ((i1 == i2 - 2) && (j1 == j2 - 1)) {
                        can_transit = true;
                    } else if ((i1 == i2 + 1) && (j1 == j2 + 2)) {
                        can_transit = true;
                    } else if ((i1 == i2 - 1) && (j1 == j2 + 2)) {
                        can_transit = true;
                    } else if ((i1 == i2 + 1) && (j1 == j2 - 2)) {
                        can_transit = true;
                    } else if ((i1 == i2 - 1) && (j1 == j2 - 2)) {
                        can_transit = true;
                    }
                    ans.A[8 * i1 + j1][8 * i2 + j2] = can_transit;
                }
            }
        }
    }
    for (int i = 0; i < 65; ++i) {
        ans.A[i][64] = 1;
    }
    ans = power<M, int64_t>(ans, n + 1);
    cout << ans.A[0][64];
}

/* 
 *  If less than K moves I can either keep moving (to any possible transition).
 *  or just take the knight out of the board (state 64), note that it doesn't count as a step.
 *  after k + 1 moves all those states when the knight taken out of the board represents the answer.
 */
