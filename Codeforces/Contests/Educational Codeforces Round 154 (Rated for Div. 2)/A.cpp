/**
 *    author:  MaGnsi0
 *    created: 31.08.2023 17:36:36
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
        int pos1, pos3;
        for (int i = 0; i < 9; ++i) {
            if (s[i] - '0' == 1) { pos1 = i; }
            if (s[i] - '0' == 3) { pos3 = i; }
        }
        cout << (pos1 < pos3 ? 13 : 31) << "\n";
    }
}
