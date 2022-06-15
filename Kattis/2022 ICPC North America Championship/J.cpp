/**
 *    author:  MaGnsi0
 *    created: 30.05.2022 21:42:50
**/
#include <bits/stdc++.h>

using namespace std;

pair<int, int> f(string s) {
    if ('X' == s[0] && s[0] == s[1] && s[1] == s[2]) {
        return make_pair(1, 0);
    }
    if ('X' == s[3] && s[3] == s[4] && s[4] == s[5]) {
        return make_pair(1, 0);
    }
    if ('X' == s[6] && s[6] == s[7] && s[7] == s[8]) {
        return make_pair(1, 0);
    }
    if ('X' == s[0] && s[0] == s[3] && s[3] == s[6]) {
        return make_pair(1, 0);
    }
    if ('X' == s[1] && s[1] == s[4] && s[4] == s[7]) {
        return make_pair(1, 0);
    }
    if ('X' == s[2] && s[2] == s[5] && s[5] == s[8]) {
        return make_pair(1, 0);
    }
    if ('X' == s[0] && s[0] == s[4] && s[4] == s[8]) {
        return make_pair(1, 0);
    }
    if ('X' == s[2] && s[2] == s[4] && s[4] == s[6]) {
        return make_pair(1, 0);
    }
    if ('O' == s[0] && s[0] == s[1] && s[1] == s[2]) {
        return make_pair(0, 1);
    }
    if ('O' == s[3] && s[3] == s[4] && s[4] == s[5]) {
        return make_pair(0, 1);
    }
    if ('O' == s[6] && s[6] == s[7] && s[7] == s[8]) {
        return make_pair(0, 1);
    }
    if ('O' == s[0] && s[0] == s[3] && s[3] == s[6]) {
        return make_pair(0, 1);
    }
    if ('O' == s[1] && s[1] == s[4] && s[4] == s[7]) {
        return make_pair(0, 1);
    }
    if ('O' == s[2] && s[2] == s[5] && s[5] == s[8]) {
        return make_pair(0, 1);
    }
    if ('O' == s[0] && s[0] == s[4] && s[4] == s[8]) {
        return make_pair(0, 1);
    }
    if ('O' == s[2] && s[2] == s[4] && s[4] == s[6]) {
        return make_pair(0, 1);
    }
    return make_pair(0, 0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    map<string, pair<int, int>> dp;
    function<pair<int, int>(string, char)> solve = [&](string s, char c) {
        if (dp.count(s)) {
            return dp[s];
        }
        pair<int, int> cur_state = f(s);
        if (cur_state != make_pair(0, 0)) {
            return dp[s] = cur_state;
        }
        dp[s] = make_pair(0, 0);
        for (int i = 0; i < 9; ++i) {
            if (s[i] == '.') {
                string t = s;
                t[i] = c;
                pair<int, int> x = solve(t, (c == 'X' ? 'O' : 'X'));
                dp[s].first += x.first;
                dp[s].second += x.second;
            }
        }
        return dp[s];
    };
    solve(".........", 'X');
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (dp.count(s) == 0) {
            cout << -1 << " " << -1 << "\n";
        } else {
            int x = count(s.begin(), s.end(), '.');
            pair<int, int> ans = solve(s, (x & 1 ? 'O' : 'X'));
            cout << ans.first << " " << ans.second << "\n";
        }
    }
}
