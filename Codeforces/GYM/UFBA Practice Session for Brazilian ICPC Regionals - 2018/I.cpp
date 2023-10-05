/**
 *    author:  MaGnsi0
 *    created: 06.09.2023 00:54:36
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
    int n; cin >> n;
    int Q; cin >> Q;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    segment_tree<int64_t> d(n - 1, 0, [](int64_t x, int64_t y) { return max(x, y); });
    for (int i = 1; i < n; ++i) {
        d.update(i - 1, abs(a[i] - a[i - 1]));
    }
    while (Q--) {
        int t; cin >> t;
        int j; cin >> j; j--;
        int64_t x; cin >> x;
        if (t == 1) {
            a[j] = x;
            if (j) {
                d.update(j - 1, abs(a[j] - a[j - 1]));
            }
            if (j + 1 < n) {
                d.update(j, abs(a[j + 1] - a[j]));
            }
        } else {
            int ans = 1;
            {
                int low = j + 1, high = n - 1, add = 0; 
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (d.query(j, mid) <= x) {
                        add = mid - j;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                ans += add;
            }
            {
                int low = 0, high = j - 1, add = 0; 
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (d.query(mid, j) <= x) {
                        add = j - mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                ans += add;
            }
            cout << ans << "\n";
        }
    }
}
