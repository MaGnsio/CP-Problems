/**
 *    author:  MaGnsi0
 *    created: 31.10.2022 19:45:46
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        segment_tree<int> maxst(n, -1, [](int x, int y) { return max(x, y); });
        segment_tree<int> minst(n, n, [](int x, int y) { return min(x, y); });
        for (int i = 0; i < n; ++i) {
            maxst.update(a[i], i);
            minst.update(a[i], i);
        }
        int64_t ans = 0;
        for (int i = 1; i <= n; ++i) {
            int mine = 0, maxe = (i + 1) / 2;
            int l = minst.query(mine, maxe);
            int r = maxst.query(mine, maxe);
            if (r - l + 1 > i) {
                continue;
            }
            int minL = max(r - i + 1, 0);
            int maxL = min(n - i, l);
            int minR = max(r, i - 1);
            int maxR = min(i + l - 1, n - 1);
            ans += min(maxL - minL + 1, maxR - minR + 1);
        }
        cout << ans << "\n";
    }
}
