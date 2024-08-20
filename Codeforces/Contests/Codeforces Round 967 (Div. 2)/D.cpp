/**
 *    author:  MaGnsi0
 *    created: 20.08.2024 18:06:31
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
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; a[i]--;
        }
        vector<vector<int>> b(n);
        for (int i = 0; i < n; ++i) {
            b[a[i]].push_back(i);
        }
        segment_tree<int> max_a(n, -1, [](int x, int y) { return max(x, y); });
        segment_tree<int> min_a(n, n, [](int x, int y) { return min(x, y); });
        segment_tree<int> las_a(n, n, [](int x, int y) { return min(x, y); });
        for (int i = 0; i < n; ++i) {
            max_a.update(i, a[i]);
            min_a.update(i, a[i]);
            if (b[i].empty()) { continue; }
            las_a.update(i, b[i].back());
        }
        bool pick_max = true;
        vector<int> ans;
        for (int i = 0; i < n; /*_*/) {
            int j = las_a.query(0, n);
            if (j == n) { break; }
            int pick = (pick_max ? max_a.query(i, j + 1) : min_a.query(i, j + 1));
            int k = *lower_bound(b[pick].begin(), b[pick].end(), i);
            for (int x : b[pick]) {
                max_a.update(x, -1);
                min_a.update(x, n);
            }
            las_a.update(pick, n);
            i = k + 1;
            ans.push_back(pick);
            pick_max ^= true;
        }
        cout << (int)ans.size() << "\n";
        for (int x : ans) {
            cout << x + 1 << " ";
        }
        cout << "\n";
    }
}
