/**
 *    author:  MaGnsi0
 *    created: 11.03.2022 21:23:03
**/
#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
    typedef int T;
    static constexpr T unit = 1;
    T f(T a, T b) { return (a && b); } // (any associative fn)
    vector<T> s; int n;
    segment_tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
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
    freopen("trains.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> L(n), R(n);
        for (int i = 0; i < n; ++i) {
            cin >> L[i] >> R[i];
        }
        vector<pair<int, int>> Ti(2 * n);
        for (int i = 0; i < n; ++i) {
            Ti[2 * i] = {L[i], n + i};
            Ti[2 * i + 1] = {R[i], i};
        }
        sort(Ti.begin(), Ti.end());
        vector<int> ans(n);
        segment_tree st(n);
        for (int i = 0; i < n; ++i) {
            st.update(i, 0);
        }
        for (int i = 0; i < 2 * n; ++i) {
            if (Ti[i].second >= n) {
                Ti[i].second -= n;
            }
            if (Ti[i].first == L[Ti[i].second]) {
                int l = 1, r = n, res = -1;
                while (l <= r) {
                    int m = (l + r) / 2;
                    if (st.query(0, m) == 0) {
                        res = m;
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
                ans[Ti[i].second] = res;
                st.update(res - 1, 1);
            } else {
                st.update(ans[Ti[i].second] - 1, 0);
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
