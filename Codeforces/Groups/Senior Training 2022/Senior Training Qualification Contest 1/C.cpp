/**
 *    author:  MaGnsi0
 *    created: 11.03.2022 19:31:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("lettercasepermutation.in", "r", stdin);
    string s;
    cin >> s;
    int n = (int)s.size();
    set<string> ans;
    for (int i = 0; i < (1LL << n); ++i) {
        string t = s;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                if (isalpha(t[j])) {
                    t[j] = tolower(t[j]);
                }
            } else {
                if (isalpha(t[j])) {
                    t[j] = toupper(t[j]);
                }
            }
        }
        ans.insert(t);
    }
    for (auto& x : ans) {
        cout << x << "\n";
    }
}
