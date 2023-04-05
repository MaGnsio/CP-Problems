/**
 *    author:  MaGnsi0
 *    created: 04.02.2023 10:23:41
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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    segment_tree<pair<int, int>> st(n, make_pair(0, -1), [&](pair<int, int> x, pair<int, int> y) { return max(x, y); });
    segment_tree<pair<int, int>> st2(n, make_pair(1e9 + 1, n), [&](pair<int, int> x, pair<int, int> y) { return min(x, y); });
    for (int i = 0; i < n; ++i) {
        st.update(i, make_pair(a[i], i));
        st2.update(i, make_pair(a[i], i));
    }
    string ans(n, '0');
    function<bool(int, int, int)> ok = [&](int l, int m, int r) {
        int L;
        for (int i = 0; i < n; ++i) {
            if (i != l && i != m && i != r) {
                L = i;
                break;
            }
        }
        int R;
        for (int i = n - 1; i >= 0; --i) {
            if (i != l && i != m && i != r) {
                R = i;
                break;
            }
        }
        st.update(l, make_pair(0, 0));
        st.update(m, make_pair(0, 0));
        st.update(r, make_pair(0, 0));
        int peak = st.query(L, R).first;
        st.update(l, make_pair(a[l], l));
        st.update(m, make_pair(a[m], m));
        st.update(r, make_pair(a[r], r));
        return peak > a[L] && peak > a[R];
    };
    for (int i = 1; i + 1 < n; ++i) {
        if (a[i] > a[0] && a[i] > a[n - 1] && ok(0, i, n - 1)) {
            ans[i] = '1';
        }
        int L = st2.query(1, i).second;
        int R = st2.query(i + 1, n - 1).second;
        if (i != 1 && a[i] > a[n - 1] && a[i] > a[L] && ok(L, i, n - 1)) {
            ans[i] = '1';
        }
        if (a[i] > a[0] && i != n - 2 && a[i] > a[R] && ok(0, i, R)) {
            ans[i] = '1';
        }
        if (i != 1 && a[i] > a[L] && i != n - 2 && a[i] > a[R] && ok(L, i, R)) {
            ans[i] = '1';
        }
    }
    cout << ans;
}
