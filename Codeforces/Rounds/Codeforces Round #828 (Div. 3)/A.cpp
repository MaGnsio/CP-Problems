/**
 *    author:  MaGnsi0
 *    created: 31.10.2022 18:57:06
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        string s;
        cin >> s;
        map<int, set<char>> mp;
        for (int i = 0; i < n; ++i) {
            mp[a[i]].insert(s[i]);
        }
        bool ok = true;
        for (auto& [_, x] : mp) {
            ok &= (int)x.size() == 1;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
