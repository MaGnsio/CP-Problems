/**
 *    author:  MaGnsi0
 *    created: 07.08.2023 22:12:24
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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int64_t> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i]; a[i] += a[i - 1];
        }
        vector<int> I(n + 1);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&](int i, int j) {
                return a[i] < a[j];
            });
        vector<int> J(n + 1);
        for (int i = 0; i <= n; ++i) {
            J[I[i]] = i;
        }
        segment_tree<int> b1(n + 1, -4 * n, [](int x, int y) { return max(x, y); });
        segment_tree<int> b2(n + 1, -4 * n, [](int x, int y) { return max(x, y); });
        segment_tree<int> b3(n + 1, -4 * n, [](int x, int y) { return max(x, y); });
        vector<int> dp(n + 1, -n);
        dp[n] = (a[n] - a[n - 1] == 0 ? 0 : (a[n] - a[n - 1] < 0 ? -1 : 1));
        b1.update(J[n], n);
        b2.update(J[n], -n);
        b3.update(J[n], 0);
        for (int i = n - 1; i > 0; --i) {
            dp[i] = dp[i + 1] + (a[i] - a[i - 1] == 0 ? 0 : (a[i] - a[i - 1] < 0 ? -1 : 1));
            int64_t sum = a[n] - a[i - 1];
            dp[i] = max(dp[i], (sum == 0 ? 0 : (sum < 0 ? -1 : 1) * n - i + 1));
            int L = 1, R = n;
            //j : p[j - 1] > p[i - 1]
            {
                int low = 1, high = n, j = -1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a[I[mid]] > a[i - 1]) {
                        j = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                //if (i == 2) { cout << j << " " << I[j] << " " << a[I[j]] << " " << (j == -1 ? -80 : b1.query(j, n + 1)) << "\n"; }
                if (j != -1) {
                    dp[i] = max(dp[i], b1.query(j, n + 1) - i + 1);
                    L = j - 1;
                }
            }
            //j : p[j - 1] > p[i - 1]
            {
                int low = 1, high = n, j = -1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a[I[mid]] < a[i - 1]) {
                        j = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                if (j != -1) {
                    dp[i] = max(dp[i], b2.query(0, j + 1) + i - 1);
                    R = j + 1;
                }
            }
            //j : p[j - 1] == p[i - 1]
            {
                if (L <= R && a[I[L]] == a[i] && a[I[R]] == a[i]) {
                    dp[i] = max(dp[i], b3.query(L, R + 1));
                }
            }
            b1.update(J[i], dp[i + 1] + i);
            b2.update(J[i], dp[i + 1] - i);
            b3.update(J[i], dp[i + 1]);
        }
        int ans = dp[1];
        cout << ans << "\n";
    }
}
