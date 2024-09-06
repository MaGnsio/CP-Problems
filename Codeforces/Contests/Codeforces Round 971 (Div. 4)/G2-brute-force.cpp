/**
 *    author:  MaGnsi0
 *    created: 07.09.2024 02:06:34
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
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        int Q; cin >> Q;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; a[i] -= i; a[i] += n;
        }
        segment_tree<int> b(2 * n + 1, 0, [](int x, int y) { return max(x, y); });
        vector<int> ans(n);
        for (int i = 0; i < k; ++i) { b.update(a[i], +1); }
        ans[0] = k - b.query(0, 2 * n + 1);
        for (int i = k; i < n; ++i) {
            b.update(a[i - k], -1);
            b.update(a[i], +1);
            ans[i - k + 1] = k - b.query(0, 2 * n + 1);
        }
        while (Q--) {
            int low; cin >> low; low--;
            int high; cin >> high; high--;
            int res = 0;
            for (int i = low, mino = INT_MAX; i <= high - k + 1; ++i) {
                mino = min(mino, ans[i]);
                res += mino;
            }
            cout << res << "\n";
        }
    }
}
