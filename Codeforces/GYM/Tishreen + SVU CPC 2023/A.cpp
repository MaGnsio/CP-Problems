/**
 *    author:  MaGnsi0
 *    created: 27.07.2023 06:21:18
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
        int x = 0, y = 0;
        for (char c : s) {
            if (c == '(') {
                x++;
            } else if (x) {
                x--;
            } else {
                y++;
            }
        }
        if (abs(y - x) & 1) {
            cout << -1 << "\n";
        } else {
            int z = abs(y - x) / 2;
            cout << min(x, y) + 2 * z << "\n";
        }
    }
}
