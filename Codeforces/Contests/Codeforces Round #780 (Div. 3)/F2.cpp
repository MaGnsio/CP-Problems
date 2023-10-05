/**
 *    author:  MaGnsi0
 *    created: 13.04.2022 03:42:10
**/
#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
    typedef int T;
    static constexpr T unit = 0;
    T f(T a, T b) { return a + b;}
    vector<T> s; int n;
    segment_tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] += val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) {
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
        string s;
        cin >> n >> s;
        vector<int64_t> a(n + 1, 0);
        a[0] = n;
        for (int i = 1; i <= n; ++i) {
            a[i] = (s[i - 1] == '+' ? -1 : 1);
            a[i] += a[i - 1];
        }
        int64_t ans = 0;
        vector<segment_tree> S(3, 2 * n + 1);
        S[a[0] % 3].update(a[0], 1);
        for (int i = 1; i <= n; ++i) {
            ans += S[a[i] % 3].query(0, a[i] + 1);
            S[a[i] % 3].update(a[i], 1);
        }
        cout << ans << "\n";
    }
}
