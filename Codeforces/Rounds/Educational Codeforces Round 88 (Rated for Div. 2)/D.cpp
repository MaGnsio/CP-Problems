/**
 *    author:  MaGnsi0
 *    created: 15.05.2023 21:02:07
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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n + 2), c(n + 2);
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i] + b[i - 1];
    }
    for (int i = n; i >= 0; --i) {
        c[i] = a[i] + c[i + 1];
    }
    segment_tree<int> d(n + 1, -INT_MAX, [](int x, int y) { return max(x, y); });
    segment_tree<int> pre(n + 2, INT_MAX, [](int x, int y) { return min(x, y); });
    segment_tree<int> suf(n + 2, INT_MAX, [](int x, int y) { return min(x, y); });
    for (int i = 0; i <= n; ++i) {
        d.update(i, a[i]);
        pre.update(i, b[i]);
        suf.update(i, c[i]);
    }
    pre.update(n + 1, b[n + 1]);
    suf.update(n + 1, c[n + 1]);
    function<int(int)> get_l = [&](int j) {
        int low = 0, high = j - 1, l = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (d.query(mid, j) > a[j]) {
                l = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return l;
    };
    function<int(int)> get_r = [&](int j) {
        int low = j + 1, high = n, r = n + 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (d.query(j + 1, mid + 1) > a[j]) {
                r = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return r + 1;
    };
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int l = get_l(i), r = get_r(i);
        int score = b[i - 1] - pre.query(l, i) + c[i + 1] - suf.query(i + 1, r);
        ans = max(ans, score);
    }
    cout << ans;
}
