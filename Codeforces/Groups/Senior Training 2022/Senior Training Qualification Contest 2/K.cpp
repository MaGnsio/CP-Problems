/**
 *    author:  MaGnsi0
 *    created: 14.03.2022 18:59:16
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

struct segment_tree {
    typedef int T;
    static constexpr T unit = 0;
    T f(T a, T b) { return (a ^ b); } // (any associative fn)
    vector<T> s; int n;
    segment_tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] += val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("hypo.in", "r", stdin);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int s = (int)sqrt(n) + 1;
    vector<tuple<int, int, int, int, int, int>> query(q);
    for (int i = 0; i < q; ++i) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        int b = l / s;
        query[i] = make_tuple(b, r, l - 1, i, x, y);
    }
    sort(query.begin(), query.end());
    vector<int> ans(q);
    segment_tree st(N);
    for (int i = 0, L = 0, R = 0; i < q; ++i) {
        int y = get<5>(query[i]);
        int x = get<4>(query[i]);
        int j = get<3>(query[i]);
        int l = get<2>(query[i]);
        int r = get<1>(query[i]);
        while (R < r) {
            st.update(a[R], 1);
            R++;
        }
        while (L > l) {
            L--;
            st.update(a[L], 1);
        }
        while (R > r) {
            R--;
            st.update(a[R], -1);
        }
        while (L < l) {
            st.update(a[L], -1);
            L++;
        }
        ans[j] = st.query(x, y + 1);
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << "\n";
    }
}
