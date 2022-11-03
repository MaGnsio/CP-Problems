/**
 *    author:  MaGnsi0
 *    created: 22.10.2022 13:07:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("in.txt", "r", stdin);
    vector<vector<pair<int, char>>> a(8, vector<pair<int, char>>(26));
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 26; ++j) {
            a[i][j] = {0, char('a' + j)};
        }
    }
    string s;
    map<int, int> mp;
    while (cin >> s) {
        mp[(int)s.size()]++;
        if ((int)s.size() > 8) {
            continue;
        }
        for (int i = 0; i < (int)s.size(); ++i) {
            a[i][s[i] - 'a'].first++;
        }
    }
    for (auto& [x, cnt] : mp) {
        cout << x << " " << cnt << "\n";
    }
    for (int i = 0; i < 8; ++i) {
        sort(a[i].begin(), a[i].end(), greater<pair<int, char>>());
        for (int j = 0; j < 10; ++j) {
            cout << a[i][j].second;
        }
        cout << "\n";
    }
}
