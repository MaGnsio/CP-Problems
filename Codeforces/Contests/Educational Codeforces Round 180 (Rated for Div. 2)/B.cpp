/**
 *    author:  MaGnsi0
 *    created: 23.06.2025 17:40:37
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
            cin >> a[i];
        }
        function<int()> F = [&]() {
            int res = INT_MAX;
            segment_tree<int> b(n, 0, [](int x, int y) { return max(x, y); });
            segment_tree<int> c(n, INT_MAX, [](int x, int y) { return min(x, y); });
            for (int i = 0; i < n; ++i) {
                b.update(i, a[i]);
                c.update(i, a[i]);
            }
            for (int i = 0; i < n; ++i) {
                int j = -1, k = -1;
                {
                    int low = i + 1, high = n - 1;
                    while (low <= high) {
                        int mid = (low + high) / 2;
                        if (b.query(i + 1, mid + 1) >= a[i] - 1) {
                            high = mid - 1; j = mid;
                        } else {
                            low = mid + 1;
                        }
                    }
                }
                {
                    int low = i + 1, high = n - 1;
                    while (low <= high) {
                        int mid = (low + high) / 2;
                        if (c.query(i + 1, mid + 1) <= a[i] + 1) {
                            high = mid - 1; k = mid;
                        } else {
                            low = mid + 1;
                        }
                    }
                }
                if (j == -1 || k == -1) { continue; }
                res = min(res, max(j, k) - i - 1);
            }
            reverse(a.begin(), a.end());
            return res;
        };
        int ans = min(F(), F());
        if (ans == INT_MAX) { ans = -1; }
        cout << ans << "\n";
    }
}
