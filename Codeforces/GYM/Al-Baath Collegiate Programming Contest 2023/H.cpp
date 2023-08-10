/**
 *    author:  MaGnsi0
 *    created: 09.07.2023 02:29:35
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

template <typename T>
struct segment_tree {
    int N;
    T E;
    vector<T> S;
    function<T(T, T)> F;
    segment_tree(int n, T e, function<T(T, T)> f) : N(n), E(e), S(2 * n, e), F(f) {}
    void update(int j, T x) {
        for (S[j += N] ^= x; j /= 2;) {
            S[j] = F(S[2 * j], S[2 * j + 1]);
        }
    }
    T query(int L, int R) {
        if (L < 0) { return 0; }
        if (R < 0) { return 0; }
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
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    vector<vector<pair<int, int>>> h(N), v(N);
    for (int i = 0; i < n; ++i) {
        int x1 = x[i], x2 = x[(i + 1) % n];
        int y1 = y[i], y2 = y[(i + 1) % n];
        if (x1 > x2) { swap(x1, x2); }
        if (y1 > y2) { swap(y1, y2); }
        if (y1 == y2) {
            h[y1].emplace_back(x1, x2);
        } else {
            v[x1].emplace_back(y1, y2);
        }
    }
    for (int i = 0; i < N; ++i) {
        sort(h[i].begin(), h[i].end());
        sort(v[i].begin(), v[i].end());
    }
    int k;
    cin >> k;
    vector<vector<pair<int, int>>> a(N);
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        a[y].emplace_back(x, i);
    }
    vector<bool> ans(k);
    segment_tree<int> b(N, 0, [](int x, int y) { return x ^ y; });
    for (int y = 0; y < N; ++y) {
        for (auto& [x1, x2] : h[y]) {
            b.update(x1, 1);
            b.update(x2, 1);
        }
        for (auto& [x, j] : a[y]) {
            ans[j] = b.query(0, x);
        }
    }
    for (int y = 0; y < N; ++y) {
        for (auto& [x, j] : a[y]) {
            int low = 0, high = h[y].size() - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (h[y][mid].first <= x && x <= h[y][mid].second) {
                    ans[j] = true;
                    break;
                } else if (x < h[y][mid].first) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        for (auto& [x, j]: a[y]) {
            int low = 0, high = v[x].size() - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (v[x][mid].first <= y && y <= v[x][mid].second) {
                    ans[j] = true;
                    break;
                } else if (y < v[x][mid].first) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << (ans[i] ? "YES" : "NO") << "\n";
    }
}
