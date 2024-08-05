/**
 *    author:  MaGnsi0
 *    created: 15.06.2024 18:21:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        string t; cin >> t;
        swap(s[0], t[0]);
        cout << s << " " << t << "\n";
    }
}
