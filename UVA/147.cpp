/**
 *    author:  MaGnsi0
 *    created: 18.05.2022 21:50:17
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> a = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    vector<int64_t> dp(N, 0);
    dp[0] = 1;
    for (int i = 0; i < (int)a.size(); ++i) {
        for (int j = a[i]; j < N; ++j) {
            dp[j] += dp[j - a[i]];
        }
    }
    double n;
    while ((cin >> n) && (n)) {
        cout << right << setw(6) << fixed << setprecision(2) << n;
        cout << right << setw(17) << dp[int(100 * n + 0.5)] << "\n";
    }
}
