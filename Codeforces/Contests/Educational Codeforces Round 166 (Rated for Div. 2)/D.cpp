/**
 *    author:  MaGnsi0
 *    created: 30.05.2024 18:55:50
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
        string s; cin >> s;
        int n = (int)s.size();
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            a[i] = (s[i - 1] == '(' ? 1 : -1) + a[i - 1];
        }
        segment_tree<int> b(n + 1, INT_MIN, [&](int x, int y) { return max(x, y); });
        for (int i = 0; i <= n; ++i) {
            b.update(i, a[i]);
        }
        map<int, vector<int>> mp;
        for (int i = 0; i <= n; ++i) {
            mp[a[i]].push_back(i);
        }
        int64_t ans = 0;
        for (int i = 1; i <= n; ++i) {
            int low = i, high = n, j = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                int mx = b.query(i, mid + 1);
                if (a[i - 1] - (mx - a[i - 1]) >= 0) {
                    j = mid, low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (j == -1) { continue; }
            ans += 1LL * (lower_bound(mp[a[i - 1]].begin(), mp[a[i - 1]].end(), j + 1) - lower_bound(mp[a[i - 1]].begin(), mp[a[i - 1]].end(), i));
        }
        cout << ans << "\n";
    }
}
