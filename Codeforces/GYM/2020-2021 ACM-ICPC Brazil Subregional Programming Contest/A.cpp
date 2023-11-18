/**
 *    author:  MaGnsi0
 *    created: 24.10.2023 06:08:15
**/
#include <bits/stdc++.h>

using namespace std;

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
    int N; cin >> N;
    int A; cin >> A;
    int B; cin >> B;
    int M = B - A + 1;
    double P = 1.0 / M;
    vector<double> ans(N + 1, 0.0);
    segment_tree<double> E(N + 1, 0.0, [](double x, double y) { return x + y; }); 
    for (int x = 1; x <= N; ++x) {
        if (A == 0) {
            ans[x] = P / (1 - P) * (M + E.query(max(0, x - B), x));
        } else {
            ans[x] = P * (E.query(max(0, x - B), max(1, x - A + 1)) + M);
        }
        E.update(x, ans[x]);
    }
    cout << fixed << setprecision(7) << ans[N];
}
