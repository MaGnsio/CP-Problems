/**
 *    author:  MaGnsi0
 *    created: 04.11.2022 17:15:25
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
    int n, q;
    cin >> n >> q;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    segment_tree<int64_t> st(n, 0, [](int64_t x, int64_t y) { return (x ^ y); });
    segment_tree<int64_t> st_max(n, -1, [](int64_t x, int64_t y) { return max(x, y); });
    for (int i = 0; i < n; ++i) {
        st.update(i, a[i]);
        st_max.update(i, a[i]);
    }
    vector<int64_t> b(n);
    b[0] = a[0];
    for (int i = 1; i < n; ++i) {
        b[i] = b[i - 1] ^ a[i];
    }
    map<int64_t, vector<int>> odds;
    map<int64_t, vector<int>> even;
    for (int i = 0; i < n; i += 2) {
        odds[b[i]].push_back(i);
        if (i + 1 < n) {
            even[b[i + 1]].push_back(i + 1);
        }
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        int64_t xor_sum = st.query(l - 1, r);
        int64_t max = st_max.query(l - 1, r);
        if (max == 0) {
            cout << 0 << "\n";
            continue;
        }
        if (xor_sum != 0) {
            cout << -1 << "\n";
            continue;
        }
        if ((r - l + 1) & 1) {
            cout << 1 << "\n";
            continue;
        }
        bool found = false, all_zeros = false;
        if (l & 1) {
            int64_t want = (l == 1 ? 0 : b[l - 2]);
            if (odds.count(want)) {
                int L = 0, R = (int)odds[want].size() - 1, j = -1;
                while (L <= R) {
                    int m = (L + R) / 2;
                    if (odds[want][m] < r) {
                        j = odds[want][m];
                        L = m + 1;
                    } else {
                        R = m - 1;
                    }
                }
                if (j != -1) {
                    if (j > l) {
                        found = true;
                        if (st_max.query(l - 1, j + 1) == 0 || st_max.query(j + 1, r) == 0) {
                            all_zeros = true;
                        }
                    }
                }
            }
        } else {
            int64_t want = (l == 1 ? 0 : b[l - 2]);
            if (even.count(want)) {
                int L = 0, R = (int)even[want].size() - 1, j = -1;
                while (L <= R) {
                    int m = (L + R) / 2;
                    if (even[want][m] < r) {
                        j = even[want][m];
                        L = m + 1;
                    } else {
                        R = m - 1;
                    }
                }
                if (j != -1) {
                    if (j > l) {
                        found = true;
                        if (st_max.query(l - 1, j + 1) == 0 || st_max.query(j + 1, r) == 0) {
                            all_zeros = true;
                        }
                    }
                }
            }
        }
        if (found && all_zeros) {
            cout << 1 << "\n";
            continue;
        }
        found = false, all_zeros = false;
        if (l & 1) {
            int64_t want = (l == 1 ? 0 : b[l - 2]);
            if (odds.count(want)) {
                auto it = lower_bound(odds[want].begin(), odds[want].end(), l - 1);
                if (it != odds[want].end()) {
                    if (*it < r) {
                        found = true;
                        if (st_max.query(l - 1, *it + 1) == 0 || st_max.query(*it + 1, r) == 0) {
                            all_zeros = true;
                        }
                    }
                }
            }
        } else {
            int64_t want = (l == 1 ? 0 : b[l - 2]);
            if (even.count(want)) {
                auto it = lower_bound(even[want].begin(), even[want].end(), l - 1);
                if (it != even[want].end()) {
                    if (*it < r) {
                        found = true;
                        if (st_max.query(l - 1, *it + 1) == 0 || st_max.query(*it + 1, r) == 0) {
                            all_zeros = true;
                        }
                    }
                }
            }
        }
        cout << (found ? (all_zeros ? 1 : 2) : -1) << "\n";
    }
}
