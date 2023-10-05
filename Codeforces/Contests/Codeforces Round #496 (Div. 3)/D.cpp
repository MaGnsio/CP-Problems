/**
 *    author:  MaGnsi0
 *    created: 09.09.2022 17:14:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1)));
    function<int(int, int, int)> solve = [&](int x, int rem, int started) {
        if (x == n) {
            return int(rem == 0 && started == 1);
        }
        int& res = dp[x][rem][started];
        if (res != -1) {
            return res;
        }
        if (s[x] == '0') {
            res = solve(x + 1, 0, 0) + (rem == 0 && started == 1) + 1;
        } else {
            res = max(solve(x + 1, (s[x] - '0') % 3, 1) + (rem == 0 && started == 1), solve(x + 1, (rem + s[x] - '0') % 3, 1));
        }
        return res;
    };
    cout << solve(0, 0, 0);
}
