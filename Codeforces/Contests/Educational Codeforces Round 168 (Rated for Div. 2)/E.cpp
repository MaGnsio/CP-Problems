/**
 *    author:  MaGnsi0
 *    created: 30.07.2024 18:18:00
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
    int Q; cin >> Q;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<pair<int, int>>> quires(n);
    for (int q = 0; q < Q; ++q) {
        int j; cin >> j; j--;
        int x; cin >> x;
        quires[j].emplace_back(q, x);
    }
    vector<bool> ans(Q, false);
    segment_tree<int64_t> b(n + 1, 0, [](int64_t x, int64_t y) { return x + y; });
    for (int i = 0; i < n; ++i) {
        int64_t low = 1, high = n, k = -1; 
        while (low <= high) {
            int64_t mid = (low + high) / 2;
            if ((b.query(0, mid + 1) / mid) + 1 <= a[i]) {
                k = mid, high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (k == -1) { continue; }
        for (auto [q, x] : quires[i]) {
            ans[q] = x >= k;
        }
        b.update(k, 1);
    }
    for (int q = 0; q < Q; ++q) {
        cout << (ans[q] ? "YES" : "NO") << "\n";
    }
}
