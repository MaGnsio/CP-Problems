/**
 *    author:  MaGnsi0
 *    created: 05.02.2023 14:50:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sort(a[i].rbegin(), a[i].rend());
        }
        function<bool(string, char)> have = [&](string s, char c) {
            return (s[0] == c) + (s[1] == c) + (s[2] == c) > 1;
        };
        function<bool(string, char)> not_have = [&](string s, char c) {
            return (s[0] == c) + (s[1] == c) + (s[2] == c) == 0;
        };
        map<string, set<int>> mp;
        for (int i = 0; i < n; ++i) {
            if (have(a[i], 'w') && not_have(a[i], 'i')) {
                mp["wi"].insert(i);
            }
            if (have(a[i], 'w') && not_have(a[i], 'n')) {
                mp["wn"].insert(i);
            }

            if (have(a[i], 'i') && not_have(a[i], 'w')) {
                mp["iw"].insert(i);
            }
            if (have(a[i], 'i') && not_have(a[i], 'n')) {
                mp["in"].insert(i);
            }

            if (have(a[i], 'n') && not_have(a[i], 'w')) {
                mp["nw"].insert(i);
            }
            if (have(a[i], 'n') && not_have(a[i], 'i')) {
                mp["ni"].insert(i);
            }
        }
        vector<tuple<int, char, int, char>> ans;
        for (auto& [x, y] : mp) {
            string rx = x;
            reverse(rx.begin(), rx.end());
            while (!y.empty() && !mp[rx].empty()) {
                ans.emplace_back(*y.begin(), x[0], *mp[rx].begin(), x[1]);
                y.erase(y.begin()), mp[rx].erase(mp[rx].begin());
            }
        }
        vector<string> remaining;
        for (auto& [x, y] : mp) {
            if (!y.empty()) {
                remaining.push_back(x);
            }
        }
        if (remaining.size() == 0) {
            cout << ans.size() << "\n";
            for (auto& [x, c1, y, c2] : ans) {
                cout << x + 1 << " " << c1 << " " << y + 1 << " " << c2 << "\n";
            }
            continue;
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (remaining[i][1] == remaining[j][0]) {
                    remaining = {remaining[i], remaining[j], remaining[3 ^ i ^ j]};
                }
            }
        }
        while (!mp[remaining[0]].empty() && !mp[remaining[1]].empty()) {
            ans.emplace_back(*mp[remaining[0]].begin(), remaining[0][0], *mp[remaining[1]].begin(), remaining[1][0]);
            string z = "";
            z += remaining[2][1];
            z += remaining[2][0];
            mp[z].insert(*mp[remaining[1]].begin());
            mp[remaining[0]].erase(mp[remaining[0]].begin());
            mp[remaining[1]].erase(mp[remaining[1]].begin());
        }
        for (auto& [x, y] : mp) {
            string rx = x;
            reverse(rx.begin(), rx.end());
            while (!y.empty() && !mp[rx].empty()) {
                ans.emplace_back(*y.begin(), x[0], *mp[rx].begin(), x[1]);
                y.erase(y.begin()), mp[rx].erase(mp[rx].begin());
            }
        }
        assert(remaining.size() == 3);
        cout << ans.size() << "\n";
        for (auto& [x, c1, y, c2] : ans) {
            cout << x + 1 << " " << c1 << " " << y + 1 << " " << c2 << "\n";
        }
    }
}
