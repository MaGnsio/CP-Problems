/**
 *    author:  MaGnsi0
 *    created: 26.10.2024 18:46:46
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int64_t solve(vector<int>& a, vector<int>& b, vector<int>& c) {
    int n = (int)a.size();
    vector<vector<int>> d(2);
    for (int i = 0; i < n; ++i) {
        d[c[i]].push_back(a[i]);
    }
    sort(d[0].rbegin(), d[0].rend());
    sort(d[1].begin(), d[1].end());
    sort(b.begin(), b.end());
    int m1 = (int)d[0].size();
    int m2 = (int)d[1].size();
    vector farthest(2, vector<int64_t>(n, n + 1));
    for (int k = 0; k < n; ++k) {
        for (int j = 0; j < m1; ++j) {
            if (d[0][j] < b[k]) { farthest[0][k] = j; break; }
        }
        for (int j = 0; j < m2; ++j) {
            if (d[1][j] > b[k]) { farthest[1][k] = j; break; }
        }
    }
    vector dp(m1 + 1, vector<int64_t>(m2 + 1, -1));
    function<int64_t(int, int)> solve = [&](int i, int j) {
        if (i == m1 && j == m2) { return int64_t(1); }
        if (dp[i][j] != -1) { return dp[i][j]; }
        int k = i + j;
        dp[i][j] = 0;
        if (i != m1) {
            int64_t x = max(int64_t(0), i - farthest[0][k] + 1);
            dp[i][j] += x * solve(i + 1, j) % MOD;
            dp[i][j] %= MOD;
        }
        if (j != m2) {
            int64_t x = max(int64_t(0), j - farthest[1][k] + 1);
            dp[i][j] += x * solve(i, j + 1) % MOD;
            dp[i][j] %= MOD;
        }
        return dp[i][j];
    };
    return solve(0, 0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n), c(n), d(n), e, f, g, done(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        if (a[i] > b[i]) { swap(a[i], b[i]); }
        if (a[i] != -1) { done[--a[i]] = true; }
        if (b[i] != -1) { done[--b[i]] = true; }
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> d[i]; d[i]--;
    }
    int64_t factor = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] != -1 && b[i] != -1) {
            if ((!c[i] && a[i] != d[i]) || (c[i] && b[i] != d[i])) {
                cout << 0;
                return 0;
            }
        } else if (b[i] != -1) {
            if (b[i] == d[i]) {
                e.push_back(d[i]);
                f.push_back(c[i]);
            } else {
                if ((!c[i] && b[i] < d[i]) || (c[i] && b[i] > d[i]) || done[d[i]]) {
                    cout << 0;
                    return 0;
                }
                done[d[i]] = 1;
            }
        } else {
            factor *= 2; factor %= MOD;
            if (done[d[i]]) {
                cout << 0;
                return 0;
            }
            done[d[i]] = true;
            e.push_back(d[i]);
            f.push_back(c[i]);
        }
    }
    for (int i = 0; i < 2 * n; ++i) {
        if (!done[i]) { g.push_back(i); }
    }
    int64_t ans = factor * solve(e, g, f) % MOD;
    cout << ans;
}
