/**
 *    author:  MaGnsi0
 *    created: 30.01.2024 17:04:39
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
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int64_t> b(n);
        b[0] = a[0];
        for (int i = 1; i < n; ++i) {
            b[i] = b[i - 1] + a[i];
        }
        function<bool(int64_t)> F = [&](int64_t x) {
            vector<int64_t> dp(n, 0);
            segment_tree<int64_t> min_dp(n + 1, OO, [](int64_t v1, int64_t v2) { return min(v1, v2); });
            min_dp.update(n, a[n - 1]);
            for (int i = n - 1; i >= 0; --i) {
                if (a[i] > x) { return false; }
                if (b[n - 1] - (i ? b[i - 1] : 0) <= x) {
                    dp[i] = 0;
                    min_dp.update(i, (i ? a[i - 1] : 0));
                    continue;
                }
                int low = i + 1, high = n - 1, j = i + 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (b[mid] - (i ? b[i - 1] : 0) > x) {
                        j = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                dp[i] = min_dp.query(i + 1, min(j + 2, n + 1));
                min_dp.update(i, dp[i] + (i ? a[i - 1] : 0));
            }
            for (int i = 0; i < n; ++i) {
                if ((i ? b[i - 1] : 0) + dp[i] <= x) {
                    return true;
                }
            }
            return false;
        };
        int64_t low = 1, high = OO, ans = OO;
        while (low <= high) {
            int64_t mid = low + (high - low) / 2;
            if (F(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
