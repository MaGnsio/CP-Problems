/**
 *    author:  MaGnsi0
 *    created: 20.11.2023 16:05:52
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e15;

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
        vector<int64_t> a(n), b(n), c(n);
        iota(c.begin(), c.end(), 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(c.begin(), c.end(), [&](int i, int j) {
                return a[i] > a[j];
            });
        set<int> S;
        for (int i = 0; i < n; ++i) {
            S.insert(a[i]);
            S.insert(b[i]);
        }
        unordered_map<int, int> I, J;
        for (int x : S) {
            J[(int)I.size()] = x;
            I[x] = (int)I.size();
        }
        int64_t noop = 0;
        for (int i = 0; i < n; ++i) {
            noop += abs(a[i] - b[i]);
        }
        int64_t ans = noop;
        int m = (int)I.size();
        set<pair<int64_t, int>> updates;
        segment_tree<int64_t> plus(m, OO, [](int64_t x, int64_t y) { return min(x, y); });
        segment_tree<int64_t> minus(m, -OO, [](int64_t x, int64_t y) { return max(x, y); });
        for (int _ = 0; _ < n; ++_) {
            int i = c[_];
            while ((!updates.empty()) && (-(updates.begin() -> first) >= a[i])) {
                {
                    auto [y, j] = *updates.begin(); y *= -1;
                    int64_t pval = plus.query(I[j], I[j] + 1);
                    pval = min(pval, abs(a[j] - b[j]) + (a[j] + b[j]));
                    plus.update(I[j], pval);
                }
                {
                    auto [y, j] = *updates.begin(); y *= -1;
                    int64_t pval = minus.query(I[j], I[j] + 1);
                    pval = max(pval, -abs(a[j] - b[j]) + (b[j] - a[j]));
                    minus.update(I[j], pval);
                }
                updates.erase(updates.begin());
            }
            cout << updates.size() << "\n";
            //noop + (b[i] - a[j]) + (a[i] - b[j]) - abs(a[j] - b[j]) - abs(a[i] - b[i])
            ans = max(ans, noop - plus.query(0, I[a[i]] + 1) + a[i] + b[i] - abs(a[i] - b[i]));
            //noop + (b[i] - a[j]) + (b[j] - a[i]) - abs(a[j] - b[j]) - abs(a[i] - b[i])
            ans = max(ans, noop + minus.query(I[a[i]], m) - a[i] + b[i] - abs(a[i] - b[i]));
            //cout << plus.query(0, I[a[i]] + 1) << " " << minus.query(I[a[i]], m) << "<==\n"; 
            updates.emplace(-b[i], i);
        }
        cout << noop << " " << ans << "\n";
    }
}
