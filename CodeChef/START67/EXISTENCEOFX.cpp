/**
 *    author:  MaGnsi0
 *    created: 30.11.2022 16:44:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        bool carry = false;
        for (int i = 0; i <= 28; ++i) {
            int ba = (a >> i) & 1;
            int bb = (b >> i) & 1;
            int bc = (c >> i) & 1;
            if (ba > bb) {
                swap(ba, bb);
            }
            if (ba == 0 && bb == 0 && bc == 1 && carry == false) {
                carry = true;
            } else if (ba == 0 && bb == 0 && bc == 1 && carry == true) {
                carry = false;
            } else if (ba == 1 && bb == 1 && bc == 0 && carry == false) {
                carry = true;
            } else if (ba == 1 && bb == 1 && bc == 0 && carry == true) {
                carry = false;
            }
        }
        cout << (!carry ? "YES" : "NO") << "\n";
    }
}
