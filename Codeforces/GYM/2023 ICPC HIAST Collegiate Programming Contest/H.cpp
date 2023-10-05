/**
 *    author:  MaGnsi0
 *    created: 27.08.2023 15:08:50
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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        set<int64_t> closed;
        for (int i = 0; i < n; ++i) {
            closed.insert(i);
        }
        segment_tree<int64_t> s(n, 0, [](int64_t x, int64_t y) { return max(x, y); });
        for (int i = 0; i < n; ++i) {
            s.update(i, a[i]);
        }
        int Q;
        cin >> Q;
        cout << s.query(0, n) << "\n";
        while (Q--) {
            int j;
            cin >> j;
            j--;
            closed.erase(j);
            int i = (closed.lower_bound(j) == closed.end() ? n - 1 : *closed.lower_bound(j));
            int64_t add = s.query(j, j + 1);
            s.update(i, add);
            cout << s.query(0, n) << "\n";
        }
    }
}
