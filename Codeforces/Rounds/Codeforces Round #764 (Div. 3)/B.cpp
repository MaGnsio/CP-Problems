/**
 *    author:  MaGnsi0
 *    created: 10.01.2022 16:35:35
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
        int ab = b - a, bc = c - b, ac = c - a;
        int na = b - bc, nb = (ac % 2 == 0 ? a + ac / 2 : -1), nc = b + ab;
        if ((na >= a && na % a == 0) || (nb >= b && nb % b == 0) || (nc >= c && nc % c == 0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
