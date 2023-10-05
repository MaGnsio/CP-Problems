/**
 *    author:  MaGnsi0
 *    created: 11.05.2022 15:58:58
**/
#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
    typedef int T;
    static constexpr T unit = 0;
    T f(T a, T b) { return (a + b); } // (any associative fn)
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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i]--;
        }
        int64_t ans = 0;
        segment_tree st(n, 0);
        for (int i = 0; i < n; ++i) {
            ans += (int64_t)st.query(a[i], n);
            st.update(a[i], 1);
        }
        cout << ans << "\n";
    }
}
