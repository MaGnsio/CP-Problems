/**
 *    author:  MaGnsi0
 *    created: 07.11.2021 21:14:36
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, k, z, test_id = 0;
int dp[N][10][2], v[N][10][2], a[N];

int solve(int pos, int left, int last) {
    int moves = pos + 2 * left;
    if (moves == k) {
        return 0;
    }
    if (v[pos][left][last] == test_id) {
        return dp[pos][left][last];
    } else {
        v[pos][left][last] = test_id;
    }
    int& res = dp[pos][left][last];
    res = 0;
    if (pos && last == 0 && left < z) {
        res = solve(pos - 1, left + 1, 1) + a[pos - 1];
    }
    if (pos < n - 1) {
        res = max(res, solve(pos + 1, left, 0) + a[pos + 1]);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        test_id++;
        cin >> n >> k >> z;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << solve(0, 0, 0) + a[0] << "\n";
    }
}
