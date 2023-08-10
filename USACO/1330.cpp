/**
 *    author:  MaGnsi0
 *    created: 06.08.2023 22:19:16
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const string T = "bessie";

int n, a[N];
pair<int, int> dp[N][6];
string S;

pair<int, int> solve(int x, int y) {
    if (x == n) {
        return {0, 0};
    }
    if (dp[x][y].first != -1) {
        return dp[x][y];
    }
    dp[x][y] = {0, 0};
    dp[x][y] = max(dp[x][y], solve(x + 1, 0));
    pair<int, int> T1 = solve(x + 1, y);
    T1.second -= a[x];
    dp[x][y] = max(dp[x][y], T1);
    if (S[x] == T[y]) {
        pair<int, int> T2 = solve(x + 1, (y + 1) % 6);
        T2.first += y == 5;
        dp[x][y] = max(dp[x][y], T2);
    }
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> S;
    n = (int)S.size();
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 6; ++j) {
            dp[i][j] = {-1, -1};
        }
    }
    pair<int, int> ans = solve(0, 0);
    cout << ans.first << "\n" << abs(ans.second);
}
