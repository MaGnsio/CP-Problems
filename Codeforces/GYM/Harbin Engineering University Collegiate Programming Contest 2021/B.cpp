/**
 *    author:  MaGnsi0
 *    created: 06/08/2021 19:22:36
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != s[i - 1]) {
            cout << 2;
            return 0;
        }
    }
    cout << -1;
}
