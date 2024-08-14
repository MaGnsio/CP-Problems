/**
 *    author:  MaGnsi0
 *    created: 14.08.2024 21:38:04
**/
#include <bits/stdc++.h>

using namespace std;

struct node {
    int sz, ans, prefix, suffix;
    node() {
        sz = ans = prefix = suffix = 0;
    }
    node(int x) {
        sz = 1; ans = prefix = suffix = x;
    }
};

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

const int N = 4e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    segment_tree<node> F(N, node(), [](node x, node y) {
        node z(0);
        z.sz = x.sz + y.sz;
        z.ans = max({x.ans, y.ans, x.suffix + y.prefix});
        z.prefix = x.prefix + (x.prefix == x.sz ? y.prefix : 0);
        z.suffix = y.suffix + (y.suffix == y.sz ? x.suffix : 0);
        return z;
    });
    for (int i = 1; i < N; ++i) {
        F.update(i, node(1));
    }
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        set<int> s;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; s.insert(x);
            F.update(x, node(0));
        }
        int Q; cin >> Q;
        while (Q--) {
            char t; cin >> t;
            if (t == '+') {
                int x; cin >> x; s.insert(x);
                F.update(x, node(0));
            } else if (t == '-') {
                int x; cin >> x; s.erase(x);
                F.update(x, node(1));
            } else {
                int k; cin >> k;
                int low = 1, high = N - 1, ans = -1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (F.query(0, mid + 1).ans >= k) {
                        ans = mid - k + 1;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                cout << ans << " ";
            }
        }
        cout << "\n";
        for (int x : s) {
            F.update(x, node(1));
        }
    }
}
