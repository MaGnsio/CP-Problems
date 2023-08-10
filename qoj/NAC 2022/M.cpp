/**
 *    author:  MaGnsi0
 *    created: 22.04.2023 21:50:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s(5, '*');
    for (char c = 'a'; c <= 'j'; ++c) {
        s[c - 'a'] = c;
    }
    set<string> s_;
    s_.insert(s);
    vector<string> ans;
    ans.push_back(s);
    function<void(string, int)> solve = [&](string t, int j) {
        if ((int)ans.size() == n) {
            for (int i = 0; i < n; ++i) {
                cout << ans[i] << "\n";
            }
            exit(0);
        }
        for (int i = 0; i < 5; ++i) {
            if (i == j) { continue; }
            for (char c = 'z'; c >= 'a'; --c) {
                if (c == t[i]) { continue; }
                string x = t;
                x[i] = c;
                if (s_.count(x)) { continue; }
                bool ok = true;
                for (int k = 0; k < 5; ++k) {
                    for (char c_ = 'a'; c_ <= 'z'; ++c_) {
                        string y = x;
                        y[k] = c_;
                        if (y != t && s_.count(y)) {
                            ok = false;
                        }
                    }
                }
                if (ok == false) { continue; }
                ans.push_back(x);
                s_.insert(x);
                solve(x, i);
                ans.pop_back();
                s_.erase(x);
            }
        }
    };
    solve(s, -1);
}
