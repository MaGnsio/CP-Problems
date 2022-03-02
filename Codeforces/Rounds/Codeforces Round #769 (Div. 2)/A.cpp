/**
 *    author:  MaGnsi0
 *    created: 07.02.2022 20:50:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        if ((n == 1) || (n == 2 && s[0] != s[1])) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
