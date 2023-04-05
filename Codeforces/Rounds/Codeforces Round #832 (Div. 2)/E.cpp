/**
 *    author:  MaGnsi0
 *    created: 09.11.2022 06:28:47
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 5e6 + 5, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    function<int64_t(int64_t, int64_t)> power = [&](int64_t b, int64_t p) {
        int64_t ans = 1;
        while (p) {
            if (p & 1) { ans = ans * b % MOD; }
            b = b * b % MOD;
            p /= 2;
        }
        return ans;
    };
    vector<int64_t> fac(N, 1), inv_fac(N);
    for (int64_t i = 2; i < N; ++i) {
        fac[i] = i * fac[i - 1]; 
        fac[i] %= MOD;
    }
    for (int i = 0; i < N; ++i) {
        inv_fac[i] = power(fac[i], MOD - 2);
    }
    function<int64_t(int64_t, int64_t)> C = [&](int64_t n, int64_t k) {
        if (k > n) { return int64_t(0); }
        int64_t ans = fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD;
        return ans;
    };
    vector<int64_t> P2(2 * N, 1);
    for (int64_t i = 1; i < 2 * N; ++i) {
        P2[i] = 2 * P2[i - 1];
        P2[i] %= MOD;
    }
    int64_t two_inv = power(2, MOD - 2);
    function<int64_t(int64_t)> F = [&](int64_t n) {
        int64_t ans = P2[n - 1] * (n + 3) % MOD * two_inv % MOD;
        return ans;
    };
    int T;
    cin >> T;
    while (T--) {
        int64_t n, m;
        cin >> n >> m;
        if (n < m) {
            swap(n, m);
        }
        int64_t ans = 0;
        for (int64_t i = 0; i <= m; ++i) {
            int64_t val = F(n + m - i);
            val %= MOD;
            val += i * P2[n + m - i - 1];
            val %= MOD;
            val *= C(n, i);
            val %= MOD;
            val *= C(m, i);
            val %= MOD;
            ans += val;
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}

/*
 * 0,0 0,1 0,2 ....
 * 1,0 1,1 1,2 ....
 * 2,0 2,1 2,2 ....
 * .   .   . .
 * .   .   .  .
 * .   .   .   .
 *            n,m
 *
 *
 * (X0, Y0) -> (X1, Y1) : X0 <= X1 <= n && Y0 <= Y1 <= m && (X0, Y0) != (X1, Y1)
 *
 * e.g. at n = 1, m = 1:
 *
 *	(0,0) (0,1)
 *	(1,0) (1,1)
 *
 *	(0,0) -> (0,1) => 2
 *	(0,0) -> (0,1) -> (1, 1) => 3
 *	(0,0) -> (1,0) -> (1, 1) => 3
 *
 * At length k there is arleady 2 points known for a&b we pick the k-2 points.
 *
 * if at point (x, y)
 * we ((n - x) * (m - y)) - 1 choices for the next points
 *
 * for m = 0 -> ans = f(n, 0) = 2*[(n-2)C0]+3*[(n-2)C1]+4*[(n-2)C2]+5*[(n-2)C3]+... = ? = 2^(n-1)*(n+3)/2 (call it linear path)
 *
 * proof:
 *	[https://www.toppr.com/ask/question/prove-that-nc1-2-cdot-nc2-3-cdot-nc3/]
 *	ans = 2*[(n-1)C0]+3*[(n-1)C1]+4*[(n-1)C2]+5*[(n-1)C3]+...
 *		= [1*[(n-1)C1]+2*[(n-1)C2]+...] + 2*[[(n-1)C0]+[(n-1)C1]+...]
 *		= (n-1) * 2^(n-2) + 2^(n) = 2^(n-1) * [(n-1)/2+2] = 2^(n-1) * (n - 1 + 4) / 2 = 2^(n-1)*(n + 3)/2
 *		
 *		
 * Now, we can divide all possible paths from (0,0) to (n,m) into several classes of one dimensional paths.
 *
 * These classes are defined by what I call breakpoints.
 * When we passes the breakpoint we turn right. Hence we can group paths by fixing the number of breakpoints.
 *
 * Assuming n>=m. For k breakpoints there are (nCk)*(mCk) ways to select for 0<=k<=m.
 * For a path with k breakpoints, n+m−k-1 points are optional,
 * that is there will exist 2^(n+m−k-1) paths with k breakpoints.
 * also we will have a linear path of length n+m-k
 * Hence:
 *	ans = f(n,m) = ∑ (n C k) * (m C k) * [f(n + m − k, 0) + 2^(n + m − k − 1) * k]
 */
