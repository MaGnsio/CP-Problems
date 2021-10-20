/**
 *    author:  MaGnsi0
 *    created: 28/09/2021 15:55:06
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;

pair<int, string> dp[N][N];
string s;

pair<int, string> best(pair<int, string> a, pair<int, string> b) {
    if (a.first == b.first) {
        return (a.second < b.second ? a : b);
    } else {
        return (a.first > b.first ? a : b);
    }
}

pair<int, string> solve(int i, int j) {
    if (i > j) {
        return {0, ""};
    }
    if (i == j) {
        string temp = "";
        temp += s[i];
        return {1, temp};
    }
    if (dp[i][j].first != -1) {
        return dp[i][j];
    }
    if (s[i] == s[j]) {
        dp[i][j].first = solve(i + 1, j - 1).first + 2;
        dp[i][j].second = s[i] + solve(i + 1, j - 1).second + s[j];
        return dp[i][j];
    }
    dp[i][j] = best(solve(i + 1, j), solve(i, j - 1));
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    while (cin >> s) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j] = {-1, ""};
            }
        }
        cout << solve(0, (int)s.size() - 1).second << "\n";
    }
}
