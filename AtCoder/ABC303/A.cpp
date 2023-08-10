/**
 *    author:  MaGnsi0
 *    created: 27.05.2023 15:01:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') { s[i] = 'l'; }
        if (s[i] == '0') { s[i] = 'o'; }
        if (t[i] == '1') { t[i] = 'l'; }
        if (t[i] == '0') { t[i] = 'o'; }
    }
    cout << (s == t ? "Yes" : "No");
}
