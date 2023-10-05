/**
 *    author:  MaGnsi0
 *    created: 19.09.2023 20:18:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = (int)s.size();
        string ans = "";
        for (int l = n / 2; l >= 1; --l) {
            map<string, vector<int>> mp;
            for (int i = 0; i + l - 1 < n; ++i) {
                mp[s.substr(i, l)].push_back(i);
            }
            int min_i = n;
            for (auto [t, a] : mp) {
                if ((int)a.size() < 2) { continue; }
                if (a[0] + l - 1 >= a.back()) { continue; }
                if (a[0] < min_i) { ans = t, min_i = a[0]; }
            }
            if (!ans.empty()) { break; }
        }
        cout << ans << "\n";
    }
}
