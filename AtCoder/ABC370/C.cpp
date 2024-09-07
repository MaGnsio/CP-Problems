/**
 *    author:  MaGnsi0
 *    created: 07.09.2024 15:08:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    string t; cin >> t;
    int n = (int)s.size();
    vector<string> ans;
    while (s != t) {
        vector<string> pick;
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                string x = s;
                x[i] = t[i];
                pick.push_back(x);
            }
        }
        sort(pick.begin(), pick.end());
        ans.push_back(pick[0]); s = pick[0];
    }
    cout << (int)ans.size() << "\n";
    for (string x : ans) {
        cout << x << "\n";
    }
}
