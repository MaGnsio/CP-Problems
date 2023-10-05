/**
 *    author:  MaGnsi0
 *    created: 23.05.2022 16:55:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, x;
    cin >> n >> x;
    if (to_string(x).size() == n) {
        cout << 0;
        return 0;
    }
    if (n == 1) {
        string s = to_string(x);
        if (s.size() == 1) {
            cout << 0;
        } else if (count(s.begin(), s.end(), '0')) {
            cout << 1;
        } else {
            cout << -1;
        }
        return 0;
    }
    int res = INT_MAX;
    map<int64_t, int> dp;
    function<void(int64_t, int)> solve = [&](int64_t a, int b) {
        if (to_string(a).size() > n || b >= res) {
            return;
        }
        if (to_string(a).size() == n) {
            res = min(res, b);
            return;
        }
        if (dp.count(a) && dp[a] <= b) {
            return;
        }
        dp[a] = b;
        set<int64_t> s;
        for (auto& c : to_string(a)) {
            if (c != '0' && c != '1') {
                s.insert(c - '0');
            }
        }
        for (auto& c : s) {
            solve(c * a, b + 1);
        }
    };
    solve(x, 0);
    cout << (res == INT_MAX ? -1 : res);
}
