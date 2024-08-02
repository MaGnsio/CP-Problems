/**
 *    author:  MaGnsi0
 *    created: 03.08.2024 00:20:28
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    set<char> C(s.begin(), s.end());
    int n = (int)C.size();
    map<char, int> mp;
    for (char c : C) {
        mp[c] = (int)mp.size();
    }
    vector<vector<int>> S(n, vector<int>(n, 0));
    for (int i = 1; i < (int)s.size(); ++i) {
        S[mp[s[i - 1]]][mp[s[i]]]++;
    }
    vector<int> dp(1 << n, OO); dp[0] = 1;
    for (int subset = 0; subset < (1 << n); ++subset) {
        for (int i = 0; i < n; ++i) {
            if (subset >> i & 1) { continue; }
            int nsubset = subset | (1 << i), cost = 0;
            for (int j = 0; j < n; ++j) {
                cost += (nsubset >> j & 1) * S[j][i];
            }
            dp[nsubset] = min(dp[nsubset], dp[subset] + cost); 
        }
    }
    int ans = dp.back();
    cout << ans;
}
