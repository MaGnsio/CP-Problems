/**
 *    author:  MaGnsi0
 *    created: 06.11.2023 11:57:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    bool ok = false;
    for (int i = 0; i + 1 < n; ++i) {
        string t = s.substr(i, 2);
        ok |= t == "ab" || t == "ba";
    }
    cout << (ok ? "Yes" : "No");
}
