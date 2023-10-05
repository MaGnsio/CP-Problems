/**
 *    author:  MaGnsi0
 *    created: 15.01.2023 14:36:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        function<pair<int, string>(int)> F = [&](int x) {
            string t(n, '*');
            vector<int> f(26, 0), remaining;
            char cur_max = 'a';
            for (int i = 0; i < n; ++i) {
                if (f[s[i] - 'a'] < x) {
                    t[i] = s[i];
                    f[t[i] - 'a']++;
                } else {
                    remaining.push_back(i);
                }
            }
            vector<int> I(26);
            iota(I.begin(), I.end(), 0);
            sort(I.begin(), I.end(), [&](int i, int j) {
                    return f[i] > f[j];
                });
            for (int j = n / x; j < 26; ++j) {
                for (int i = 0; i < n; ++i) {
                    if (t[i] - 'a' == I[j]) {
                        t[i] = '*';
                        remaining.push_back(i);
                    }
                }
            }
            for (int j = 0; j < n / x; ++j) {
                while (f[I[j]] < x && !remaining.empty()) {
                    t[remaining.back()] = char('a' + I[j]);
                    remaining.pop_back();
                    f[I[j]]++;
                }
            }
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                ans += s[i] != t[i];
            }
            return make_pair(ans, t);
        };
        pair<int, string> ans = {n + 1, ""};
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                if (n / i <= 26) {
                    ans = min(ans, F(i));
                }
                if (i <= 26) {
                    ans = min(ans, F(n / i));
                }
            }
        }
        cout << ans.first << "\n";
        cout << ans.second << "\n";
    }
}
