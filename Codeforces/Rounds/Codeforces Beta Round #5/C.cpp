/**
 *    author:  MaGnsi0
 *    created: 03.03.2022 14:24:59
**/
#include <bits/stdc++.h>

using namespace std;

pair<int, int> solve(string s) {
    int n = (int)s.size();
    vector<int> f(n + 1, 0);
    f[0] = 1;
    for (int i = 0; i < n;) {
        if (s[i] == ')') {
            i++;
            continue;
        }
        stack<char> _s;
        for (int j = i; j < n; ++j) {
            if (s[j] == '(') {
                _s.push(s[j]);
            } else {
                if (_s.empty()) {
                    i = j + 1;
                    break;
                }
                _s.pop();
            }
            if (_s.empty()) {
                f[j - i + 1]++;
            }
            if (j == n - 1) {
                i = n;
                break;
            }
        }
    }
    for (int i = n; i >= 0; --i) {
        if (f[i]) {
            return make_pair(i, f[i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    pair<int, int> ans = solve(s);
    for (auto& c : s) {
        c = (c == ')' ? '(' : ')');
    }
    reverse(s.begin(), s.end());
    ans = max(ans, solve(s));
    cout << ans.first << " " << ans.second;
}
