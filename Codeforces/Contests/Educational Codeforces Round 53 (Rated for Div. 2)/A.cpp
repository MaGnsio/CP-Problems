/**
 *    author:  MaGnsi0
 *    created: 16.10.2023 15:47:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] != s[i + 1]) {
            cout << "YES\n";
            cout << s.substr(i, 2);
            return 0;
        }
    }
    cout << "NO";
}
