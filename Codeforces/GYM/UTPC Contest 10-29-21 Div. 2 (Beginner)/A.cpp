/**
 *    author:  MaGnsi0
 *    created: 21.11.2021 15:30:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); ++i) {
        if ((s[i] - '0') % 2 == 0) {
            cout << "SAD";
            return 0;
        }
    }
    cout << "HAPPY";
}
