/**
 *    author:  MaGnsi0
 *    created: 09.09.2023 22:12:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    cin.ignore();
    map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        string s, t = "";
        getline(cin, s);
        for (int j = 0; j < (int)s.size(); ++j) {
            if (j == 0 || s[j - 1] == ' ') { t += s[j]; }
        }
        mp[t]++;
    }
    int64_t ans = 0;
    for (auto [_, x] : mp) {
        ans += 1LL * x * (x - 1) / 2;
    }
    cout << ans;
}
