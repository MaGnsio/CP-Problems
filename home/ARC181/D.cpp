/**
 *    author:  MaGnsi0
 *    created: 04.08.2024 16:37:20
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
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; a[i]--;
    }
    vector<int64_t> inversions(n, 0);
    segment_tree<int> b(n, 0, [](int64_t x, int64_t y) { return x + y; });
    for (int i = 0; i < n; ++i) {
        inversions[i] = b.query(a[i], n);
        b.update(a[i], 1);
    }
    int m; cin >> m;
    vector<int64_t> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i]; c[i]--;
    }
    segment_tree<int64_t> ans(m + 1, 0, [](int64_t x, int64_t y) { return x + y; });
    for (int i = 0; i < n; ++i) {
        int low = 0, high = m - 1, j = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (c[mid] >= i) {
                j = mid, high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (j == -1) { continue; }
        if (inversions[i] == 0) { continue; }
        int k = min(int(j + inversions[i] - 1), m - 1);
        ans.update(j, 1);
        ans.update(k + 1, -1);
    }
    int64_t total = 0;
    for (int i = 0; i < n; ++i) {
        total += inversions[i];
    }
    for (int i = 0; i < m; ++i) {
        total -= ans.query(0, i + 1);
        cout << total << "\n";
    }
}
