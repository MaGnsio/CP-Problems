/**
 *    author:  MaGnsi0
 *    created: 28.08.2023 18:08:18
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
        for (S[j += N] += x; j /= 2;) {
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
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    vector<int> L1(m), R1(m);
    for (int i = 0; i < m; ++i) {
        cin >> L1[i] >> R1[i];
    }
    vector<vector<int>> B(n + 1);
    for (int i = 0; i < n; ++i) {
        B[A[i]].push_back(i);
    }
    vector<int> S(n + 1);
    for (int i = 1; i <= n; ++i) {
        S[i] = S[i - 1] + (int)B[i].size();
    }
    vector<int> ans(m);
    for (int i = 0; i < m; ++i) {
        ans[i] = S[R1[i]] - S[L1[i] - 1];
    }
    vector<int> L2, R2;
    segment_tree<int> S1(n, 0, [](int x, int y) { return max(x, y); });
    for (int i = 1; i <= n; ++i) {
        int k = (int)B[i].size();
        for (int j = 0; j < k - 1; ++j) {
            int x = B[i][j], y = B[i][j + 1];
            int z = S1.query(x + 1, y);
            L2.push_back(z);
            R2.push_back(i);
        }
        for (int j = 0; j < k; ++j) {
            S1.update(B[i][j], i);
        }
    }
    int k = (int)L2.size();
    vector<vector<int>> I1(n + 1), I2(n + 1);
    for (int i = 0; i < m; ++i) {
        I1[L1[i]].push_back(i);
    }
    for (int i = 0; i < k; ++i) {
        I2[L2[i]].push_back(i);
    }
    segment_tree<int> S2(n + 1, 0, [](int x, int y) { return x + y; });
    for (int i = 0; i <= n; ++i) {
        for (int j : I1[i]) {
            ans[j] -= S2.query(L1[j], R1[j] + 1);
        }
        for (int j : I2[i]) {
            S2.update(R2[j], 1);
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << "\n";
    }
}
