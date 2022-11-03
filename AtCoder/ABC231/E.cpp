/**
 *    author:  MaGnsi0
 *    created: 11.12.2021 13:52:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<long long, long long> dp;
    function<long long(long long, int)> solve = [&](long long cur, int i) {
        if (cur == 0) {
            return 0LL;
        }
        if (dp.find(cur) != dp.end()) {
            return dp[cur];
        }
        if (i == n - 1) {
            return cur / a[n - 1];
        }
        long long f = (cur / a[i + 1]), c = ((cur + a[i + 1] - 1) / a[i + 1]);
        long long res = solve(f * a[i + 1], i + 1) + (cur - f * a[i + 1]) / a[i];
        res = min(res, solve(c * a[i + 1], i + 1) + (c * a[i + 1] - cur) / a[i]);
        return dp[cur] = res;
    };
    cout << solve(x, 0);
}
