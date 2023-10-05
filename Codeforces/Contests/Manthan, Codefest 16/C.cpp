/**
 *    author:  MaGnsi0
 *    created: 21.04.2023 04:31:30
**/
#include <bits/stdc++.h>

using namespace std;

struct node {
    int end = 0;
    array<int, 26> next;
    node() {
        fill(next.begin(), next.end(), -1);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    reverse(s.begin(), s.end());
    int m;
    cin >> m;
    vector<node> a(1);
    map<string, string> mp;
    function<void(string)> insert = [&](string t) {
        int root = 0;
        for (char c : t) {
            if (a[root].next[c - 'a'] == -1) {
                a[root].next[c - 'a'] = (int)a.size();
                a.push_back(node());
            }
            root = a[root].next[c - 'a'];
        }
        a[root].end = 1;
    };
    for (int i = 0; i < m; ++i) {
        string t;
        cin >> t;
        string x = t;
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        mp[x] = t;
        insert(x);
    }
    vector<int> dp(n, -1);
    function<int(int)> solve = [&](int j) {
        if (j == n) {
            return 1;
        }
        if (dp[j] != -1) {
            return dp[j];
        }
        dp[j] = 0;
        int root = 0;
        for (int i = j; i < n; ++i) {
            if (a[root].next[s[i] - 'a'] == -1) {
                break;
            }
            root = a[root].next[s[i] - 'a'];
            if (a[root].end) {
                dp[j] |= solve(i + 1);
            }
        }
        return dp[j];
    };
    assert(solve(0) == 1);
    vector<string> ans;
    function<void(int)> build = [&](int j) {
        if (j == n) {
            return;
        }
        int root = 0;
        for (int i = j; i < n; ++i) {
            root = a[root].next[s[i] - 'a'];
            if (a[root].end && solve(i + 1)) {
                build(i + 1);
                ans.push_back(mp[s.substr(j, i - j + 1)]);
                break;
            }
        }
        return;
    };
    build(0);
    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i] << " ";
    }
}
