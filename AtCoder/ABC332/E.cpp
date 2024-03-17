/**
 *    author:  MaGnsi0
 *    created: 10.12.2023 14:35:10
**/
#include <bits/stdc++.h>

using namespace std;

const double OO = 1e18;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int D; cin >> D;
    vector<int64_t> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    int M = 1 << N;
    vector<int64_t> sums(M);
    for (int mask = 0; mask < M; ++mask) {
        for (int i = 0; i < N; ++i) {
            if (mask >> i & 1) {
                sums[mask] += a[i];
            }
        }
    }
    double avg = 0;
    for (int i = 0; i < N; ++i) {
        avg += a[i];
    }
    avg = 1.0 * avg / D;
    vector<vector<bool>> done(D, vector<bool>(M));
    vector<vector<double>> dp(D, vector<double>(M));
    function<double(int, int)> solve = [&](int bag, int mask) {
        if (bag == D) {
            return 1.0 * (mask != M - 1) * OO;
        }
        if (done[bag][mask]) {
            return dp[bag][mask];
        }
        done[bag][mask] = true;
        dp[bag][mask] = OO;
        for (int sub = mask ^ (M - 1); sub; sub = (sub - 1) & (mask ^ (M - 1))) {
            double add = sums[sub] - avg;
            add *= add, add /= D;
            dp[bag][mask] = min(dp[bag][mask], solve(bag + 1, mask | sub) + add);
        }
        return dp[bag][mask];
    };
    cout << fixed << setprecision(10) << solve(0, 0);
}
