/**
 *    author:  MaGnsi0
 *    created: 03.05.2023 18:05:27
**/
#include <bits/stdc++.h>

using namespace std;

struct node {
    int x;
    array<int, 2> next;
    node() {
        x = 0;
        next[0] = next[1] = -1;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    string s;
    cin >> s >> k;
    n = (int)s.size();
    vector<vector<bool>> ok(n, vector<bool>(n, false));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; i + j < n; ++j) {
            ok[j][i + j] = s[j] == s[i + j];
        }
    }
    for (int i = 5; i < n; ++i) {
        for (int j = 0; i + j < n; ++j) {
            ok[j][i + j] = (ok[j + 2][i + j - 2] && s[j] == s[i + j]);
        }
    }
    vector<node> a(1);
    function<void(int)> insert = [&](int j) {
        int root = 0;
        for (int i = j; i < n; ++i) {
            if (a[root].next[s[i] - 'a'] == -1) {
                a[root].next[s[i] - 'a'] = (int)a.size();
                a.push_back(node());
            }
            root = a[root].next[s[i] - 'a'];
            a[root].x += ok[j][i];
        }
    };
    for (int i = 0; i < n; ++i) {
        insert(i);
    }
    function<int(int)> dfs = [&](int j) {
        if (j == -1) {
            return 0;
        }
        a[j].x += dfs(a[j].next[0]);
        a[j].x += dfs(a[j].next[1]);
        return a[j].x;
    };
    string ans = "";
    function<void(int)> solve = [&](int j) {
        int x  = a[j].x;
        if (a[j].next[0] != -1) { x -= a[a[j].next[0]].x; }
        if (a[j].next[1] != -1) { x -= a[a[j].next[1]].x; }
        if (x >= k) { return; }
        k -= x;
        if (a[j].next[0] != -1 && a[a[j].next[0]].x >= k) {
            ans += "a";
            solve(a[j].next[0]);
        } else if (a[j].next[1] != -1) {
            if (a[j].next[0] != -1) { k -= a[a[j].next[0]].x; }
            ans += "b";
            solve(a[j].next[1]);
        }
    };
    dfs(0);
    solve(0);
    cout << ans;
}
