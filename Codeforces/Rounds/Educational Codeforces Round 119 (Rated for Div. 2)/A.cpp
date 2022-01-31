/**
 *    author:  MaGnsi0
 *    created: 13.01.2022 23:31:43
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
        cout << (count(s.begin(), s.end(), 'N') == 1 ? "NO\n" : "YES\n");
    }
}
