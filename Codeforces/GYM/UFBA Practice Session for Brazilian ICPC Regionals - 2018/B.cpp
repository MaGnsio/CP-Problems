/**
 *    author:  MaGnsi0
 *    created: 06.09.2023 00:02:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    string t; cin >> t;
    int n = (int)s.size();
    int m = (int)t.size();
    vector<bool> ans(n, false);
    for (int _ = 0; _ < 2; ++_) {
        for (int i = 0; i + m - 1 < n; ++i) {
            bool ok = true;
            char one = '-', two = '-';
            for (int j = 0; j < m; ++j) {
                if (t[j] == '1') {
                    if (one == '-') {
                        one = s[i + j];
                    } else if (one != s[i + j]) {
                        ok = false;
                        break;
                    }
                }
                if (t[j] == '0') {
                    if (two == '-') {
                        two = s[i + j];
                    } else if (two != s[i + j]) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                if (_ == 0) {
                    ans[i] = true;
                } else {
                    ans[(n - i - 1) - m + 1] = true;
                }
            }
        }
        reverse(s.begin(), s.end());
    }
    cout << count(ans.begin(), ans.end(), true);
}
