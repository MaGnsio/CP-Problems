/**
 *    author:  MaGnsi0
 *    created: 22.09.2022 19:04:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int64_t> b(4 * (n + 1), 0);
    function<void(int, int64_t)> update = [&](int j, int64_t x) {
        int i = 0, l = 0, r = n;
        while (true) {
            b[i] += x;
            if (l == r) {
                break;
            }
            int m = (l + r) / 2;
            if (l <= j && j <= m) {
                i = 2 * i + 1;
                l = l;
                r = m;
            } else {
                i = 2 * i + 2;
                l = m + 1;
                r = r;
            }
        }
    };
    function<int64_t(int, int, int, int, int)> query = [&](int j, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return b[j];
        }
        if (R < l || r < L) {
            return int64_t(0);
        }
        int m = (l + r) / 2;
        return query(2 * j + 1, l, m, L, R) + query(2 * j + 2, m + 1, r, L, R);
    };
    function<int64_t(int)> F = [&](int j) {
        return query(0, 0, n, 0, j);
    };
    function<bool(int64_t, vector<int64_t>&)> add = [](int64_t x, vector<int64_t>& basis) {
        for (int i = 0; i < (int)basis.size(); ++i) {
            if (!((x >> i) & 1)) {
                continue;
            }
            if (basis[i]) {
                x ^= basis[i];
            } else {
                basis[i] = x;
                return true;
            }
        }
        return false;
    };
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            update(l - 1, x);
            update(r, -x);
        } else {
            int l, r;
            cin >> l >> r;
            bool ok = false;
            vector<int64_t> basis(32, 0);
            for (int j = l - 1; j < r; ++j) {//this loop will just go for maximum 32 iteration.
                int64_t x = a[j] + F(j);
                if (!add(x, basis)) { //there is a way to represent x with some previous element, so we can get a subsequence with xor equal to 0.
                    ok = true;
                    break;
                }
            }
            cout << (ok ? "Yes" : "No") << "\n";
        }
    }
}
