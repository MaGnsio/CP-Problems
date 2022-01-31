/**
 *    author:  MaGnsi0
 *    created: 24.01.2022 22:24:41
**/
#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
	typedef bool T;
	static constexpr T unit = true;
	T f(T a, T b) { return (a && b); }
	vector<T> s; int n;
	segment_tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
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
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> b(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            b[a[i]]++;
        }
        segment_tree st(n + 1);
        for (int i = 0; i <= n; ++i) {
            st.update(i, b[i]);
        }
        int start = 0;
        vector<int> res;
        while (start != n) {
            int l = 0, r = n + 1, mex = 0;
            while (l <= r) {
                int m = (l + r) / 2;
                if (st.query(0, m)) {
                    mex = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            if (mex == 0) {
                for (int i = start; i < n; ++i) {
                    res.push_back(0);
                }
                break;
            }
            segment_tree c(n + 1, false);
            for (int i = start; i < n; ++i) {
                c.update(a[i], true);
                if (!--b[a[i]]) {
                    st.update(a[i], false);
                }
                if (c.query(0, mex)) {
                    start = i + 1;
                    break;
                }
            }
            res.push_back(mex);
        }
        cout << (int)res.size() << "\n";
        for (int i = 0; i < (int)res.size(); ++i) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}
