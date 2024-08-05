/**
 *    author:  MaGnsi0
 *    created: 22.06.2024 15:11:45
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

bool is_palindrome(string s) {
    int n = (int)s.size();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) { return false; }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int k; cin >> k;
    string s; cin >> s;
    vector<map<string, int64_t>> dp(n);
    function<int64_t(int, string)> solve = [&](int x, string p) {
        if ((int)p.size() == k && is_palindrome(p)) { return int64_t(0); }
        if (x == n) { return int64_t(1); }
        if (dp[x].count(p)) { return dp[x][p]; }
        string pa = (x < k ? p + "A" : p.substr(1) + "A");
        string pb = (x < k ? p + "B" : p.substr(1) + "B");
        if (s[x] != '?') {
            dp[x][p] = solve(x + 1, s[x] == 'A' ? pa : pb);
        } else {
            dp[x][p] = (solve(x + 1, pa) + solve(x + 1, pb)) % MOD;
        }
        return dp[x][p];
    };
    int64_t ans = solve(0, "");
    cout << ans;
}
