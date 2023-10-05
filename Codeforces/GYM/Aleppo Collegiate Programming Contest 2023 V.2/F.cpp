/**
 *    author:  MaGnsi0
 *    created: 31.08.2023 22:31:54
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 1e5 + 5;

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
    segment_tree<int64_t> values(M, 0, [&](int64_t x, int64_t y) { return x + y; });
    segment_tree<int64_t> counts(M, 0, [&](int64_t x, int64_t y) { return x + y; });
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int64_t> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            a[i] = (a[i] % m + a[i - 1]) % m;
        }
        function<pair<int64_t, int64_t>(int, int, int)> G = [&](int L, int R, int y) {
            pair<int64_t, int64_t> add = {0, 0};
            int L1 = L, R1 = min(R, y); 
            int L2 = max(L, R1 + 1), R2 = R; 
            if (L1 <= R1) {
                add.first += y * counts.query(L1, R1 + 1) - values.query(L1, R1 + 1);
            }
            if (L2 <= R2) {
                add.first += (m + y) * counts.query(L2, R2 + 1) - values.query(L2, R2 + 1);
            }
            add.second = counts.query(L, R + 1);
            return add;
        };
        function<pair<int64_t, int64_t>(int)> F = [&](int x) {
            pair<int64_t, int64_t> ans = {0, 0};
            for (int i = 0; i <= n; ++i) {
                int L = (a[i] + 1) % m;
                int R = (a[i] - x + m) % m;
                if (L <= R) {
                    pair<int64_t, int64_t> add = G(L, R, a[i]);
                    ans.first += add.first;
                    ans.second += add.second;
                } else {
                    int L1 = L, R1 = m - 1;
                    pair<int64_t, int64_t> add1 = G(L1, R1, a[i]);
                    ans.first += add1.first;
                    ans.second += add1.second;
                    int L2 = 0, R2 = R;
                    pair<int64_t, int64_t> add2 = G(L2, R2, a[i]);
                    ans.first += add2.first;
                    ans.second += add2.second;
                }
                values.update(a[i], +a[i]);
                counts.update(a[i], +1);
            }
            for (int i = 0; i <= n; ++i) {
                values.update(a[i], -a[i]);
                counts.update(a[i], -1);
            }
            return ans;
        };
        int low = 0, high = m - 1, lowest = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (F(mid).second >= k) {
                lowest = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        pair<int64_t, int64_t> P = (lowest != m - 1 ? F(lowest + 1) : make_pair(0LL, 0LL));
        int64_t ans = P.first + (k - P.second) * lowest;
        cout << ans << "\n";
    }
}
