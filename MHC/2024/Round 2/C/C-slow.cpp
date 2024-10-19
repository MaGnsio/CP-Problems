/**
 *    author:  MaGnsi0
 *    created: 19.10.2024 22:19:02
**/
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

struct FT2 {
	vector<vi> ys; vector<FT> ft;
	FT2(int limx) : ys(limx) {}
	void fakeUpdate(int x, int y) {
		for (; x < sz(ys); x |= x + 1) ys[x].push_back(y);
	}
	void init() {
		for (vi& v : ys) sort(all(v)), ft.emplace_back(sz(v));
	}
	int ind(int x, int y) {
		return (int)(lower_bound(all(ys[x]), y) - ys[x].begin()); }
	void update(int x, int y, ll dif) {
		for (; x < sz(ys); x |= x + 1)
			ft[x].update(ind(x, y), dif);
	}
	ll query(int x, int y) {
		ll sum = 0;
		for (; x; x &= x - 1)
			sum += ft[x-1].query(ind(x-1, y));
		return sum;
	}
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int n; cin >> n;
        int m; cin >> m;
        int64_t k; cin >> k;
        vector a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j]; a[i][j]--;
            }
        }
        vector b(n * m, vector<pair<int, int>>());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                b[a[i][j]].emplace_back(i, j);
            }
        }
        function<int64_t(int)> F = [&](int x) {
            FT2 ft(n);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    ft.fakeUpdate(i, j);
                }
            }
            ft.init();
            int64_t res = 0;
            for (int k = 0; k < n * m; ++k) {
                for (auto [i, j] : b[k]) {
                    int xl = max(0, i - x);
                    int xr = min(n - 1, i + x);
                    int yl = max(0, j - x);
                    int yr = min(m - 1, j + x);
                    res += ft.query(xr + 1, yr + 1);
                    res -= (xl ? ft.query(xl, yr + 1) : 0);
                    res -= (yl ? ft.query(xr + 1, yl) : 0);
                    res += (xl && yl ? ft.query(xl, yl) : 0);
                }
                for (auto [i, j] : b[k]) {
                    ft.update(i, j, 1);
                }
            }
            return 2LL * res;
        };
        int low = 1, high = max(n, m) - 1, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (F(mid) >= k) {
                ans = mid; high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
