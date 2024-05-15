/**
 *    author:  MaGnsi0
 *    created: 13.05.2024 18:36:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = (int)s.size();
    vector<pair<int, int>> a;
    for (int i = 0, p = 0; i < n; ++i) {
        a.emplace_back(p, -i);
        p += s[i] == '(' ? 1 : -1;
    }
    sort(a.begin(), a.end());
    for (auto [_, j] : a) {
        cout << s[-j];
    }
}
