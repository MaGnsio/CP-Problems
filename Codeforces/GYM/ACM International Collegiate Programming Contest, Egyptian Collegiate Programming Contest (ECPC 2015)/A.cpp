/**
 *    author:  MaGnsi0
 *    created: 20.06.2023 17:52:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<map<string, int>> mp(10);
    for (int i = 1; i < 10; ++i) {
        string s = "";
        for (int j = 1; j <= i; ++j) {
            s += char('0' + j);
        }
        do {
            mp[i][s] = (int)mp[i].size();
        } while (next_permutation(s.begin(), s.end()));
    }
    map<pair<int, int>, long double> dp;
    function<long double(int, int)> solve = [&](int j, int x) {
        if (j == (int)mp[x].size()) {
            long double O = 0;
            return O;
        }
        long double X = 1.0 / (int)mp[x].size();
        if (j == (int)mp[x].size() - 1) {
            return X; 
        }
        if (dp.count(make_pair(x, j))) {
            return dp[{x, j}];
        }
        dp[{x, j}] = X * solve(j + 1, x) + solve(j + 1, x);
        return dp[{x, j}];
    };
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        string t = s;
        sort(t.begin(), t.end());
        int x = (int)s.size();
        map<char, char> mp2;
        for (int i = 0; i < x; ++i) {
            mp2[t[i]] = char('0' + i + 1);
        }
        for (int i = 0; i < x; ++i) {
            s[i] = mp2[s[i]];
        }
        cout << fixed << setprecision(9) << solve(mp[x][s] + 1, x) << "\n";
    }
}
