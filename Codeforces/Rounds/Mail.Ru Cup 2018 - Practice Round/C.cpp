/**
 *    author:  MaGnsi0
 *    created: 20/09/2021 20:30:08
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 60, K = 2e3 + 3, OO = 1e9;
int n, s, k;
string c;
vector<int> A(N);
vector<vector<int>> dp(N, vector<int>(K, -1));

int solve(int i, int j) {
    if (j <= 0) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    dp[i][j] = OO;
    for (int x = 0; x < n; ++x) {
        if (c[x] == c[i] || A[x] <= A[i]) {
            continue;
        }
        dp[i][j] = min(dp[i][j], solve(x, j - A[x]) + abs(i - x));
    }
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    cin >> n >> s >> k;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    cin >> c;
    int ans = OO;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, solve(i, k - A[i]) + abs(s - i - 1));
    }
    cout << (ans == OO ? -1 : ans);
}
