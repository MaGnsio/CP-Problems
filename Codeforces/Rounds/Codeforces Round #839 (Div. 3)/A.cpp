/**
 *    author:  MaGnsi0
 *    created: 31.01.2023 21:10:17
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
        cout << s[0] + s[2] - 2 * '0' << "\n";
    }
}
