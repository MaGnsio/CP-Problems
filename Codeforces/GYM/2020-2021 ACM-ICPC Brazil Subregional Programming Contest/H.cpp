/**
 *    author:  MaGnsi0
 *    created: 24.10.2023 15:27:37
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<int64_t>> C(N, vector<int64_t>(N));
    for (int i = 0; i < N; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    int n; cin >> n;
    int k; cin >> k;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    function<int64_t(int, int64_t, int64_t, int, int)> solve = [&](int j, int64_t sum, int64_t upper, int have, int limit) {
        if (have == limit) { return int64_t(1); }
        if (j == n) { return int64_t(have == limit); }
        int64_t res = 0;
        if (sum + a[j] <= upper) {
            res = solve(j + 1, sum + a[j], upper, have + 1, limit) + C[n - j - 1][limit - have];
        } else {
            res = solve(j + 1, sum, upper, have, limit);
        }
        return res;
    };
    int64_t L; cin >> L;
    int64_t R; cin >> R;
    int64_t ans = solve(0, 0, R, 0, k) - solve(0, 0, L - 1, 0, k);
    cout << ans;
}
