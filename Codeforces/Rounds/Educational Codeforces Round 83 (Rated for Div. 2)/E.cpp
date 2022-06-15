/**
 *    author:  MaGnsi0
 *    created: 17.04.2022 03:04:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    function<int(int, int)> F = [&](int l, int r) {
        stack<int> s;
        for (int i = l; i <= r; ++i) {
            int x = a[i];
            while (!s.empty() && s.top() == x) {
                s.pop();
                x++;
            }
            s.push(x);
        }
        return (int)s.size();
    };
    function<int(int, int)> solve = [&](int l, int r) {
        if (l == r) {
            return 1;
        }
        if (l + 1 == r) {
            return (a[l] == a[r] ? 1 : 2);
        }
        int& ans = dp[l][r];
        if (ans != -1) {
            return ans;
        }
        ans = F(l, r);
        for (int i = l; i < r; ++i) {
            ans = min(ans, solve(l, i) + solve(i + 1, r));
        }
        return ans;
    };
    cout << solve(0, n - 1);
}
