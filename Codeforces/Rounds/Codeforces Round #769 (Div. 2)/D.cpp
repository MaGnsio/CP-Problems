/**
 *    author:  MaGnsi0
 *    created: 07.02.2022 20:50:55
**/
#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
    typedef int T;
    static constexpr T unit = 0;
    T f(T a, T b) {
        return __gcd(a, b);
    }
    int n;
    vector<T> s;
    segment_tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;) {
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
        }
    }
    T query(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) {
                ra = f(ra, s[b++]);
            }
            if (e % 2) {
                rb = f(s[--e], rb);
            }
        }
        return f(ra, rb);
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
    segment_tree st(n);
    for (int i = 0; i < n; ++i) {
        st.update(i, a[i]);
    }
    int last_changed = -1 + (a[0] == 1);
    vector<int> res(n);
    res[0] = a[0] == 1;
    for (int i = 1; i < n; ++i) {
        int l = last_changed + 1, r = i;
        res[i] = res[i - 1];
        while (l <= r) {
            int m = (l + r) / 2;
            int g = st.query(m, i + 1);
            int k = i - m + 1;
            if (g == k) {
                res[i]++;
                last_changed = i;
                break;
            } else if (g > k) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
}
