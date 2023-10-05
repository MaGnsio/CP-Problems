/**
 *    author:  MaGnsi0
 *    created: 28.11.2022 11:37:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        s.insert(s.end(), s.rbegin(), s.rend());
        cout << s << "\n";
    }
}
