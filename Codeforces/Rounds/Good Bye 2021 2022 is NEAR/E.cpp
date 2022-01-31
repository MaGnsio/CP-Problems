/**
 *    author:  MaGnsi0
 *    created: 31.12.2021 15:07:48
**/
#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
	typedef long long T;
	static constexpr T unit = 0;
	T f(T a, T b) {return (a + b);}
	vector<T> s; int n;
	segment_tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] += val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int e) {
        int b = 0;
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
        string s, t;
        cin >> n >> s >> t;
        vector<vector<int>> a(26);
        for (int i = n - 1; i >= 0; --i) {
            a[s[i] - 'a'].push_back(i);
        }
        long long res = LLONG_MAX, swaps = 0;
        segment_tree st(n);
        for (int i = 0; i < n; ++i) {
            int best = -1;
            for (int j = 0; j < t[i] - 'a'; ++j) {
                if (a[j].empty()) {
                    continue;
                }
                if (best == -1 || a[j].back() < best) {
                    best = a[j].back();
                }
            }
            if (best != -1) {
                best += st.query(best + 1);
                res = min(res, swaps + best - i);
            }
            if (a[t[i] - 'a'].empty()) {
                break;
            }
            int j = a[t[i] - 'a'].back();
            swaps += (j + st.query(j + 1) - i);
            st.update(0, 1);
            st.update(j, -1);
            a[t[i] - 'a'].pop_back();
        }
        cout << (res == LLONG_MAX ? -1 : res) << "\n";
    }
}
