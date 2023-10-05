/**
 *    author:  MaGnsi0
 *    created: 18.08.2022 15:34:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int g1 = __gcd(a, b), g2 = __gcd(c, d);
        a /= g1, b /= g1, c /= g2, d /= g2;
        if (a == c && b == d) {
            cout << 0 << "\n";
        } else if (!a || !c) {
            cout << 1 << "\n";
        } else if (a == c && __gcd(b, d) == min(b, d)) {
            cout << 1 << "\n";
        } else if (a < c && gcd(a, c) == a && __gcd(b, d) == d) {
            cout << 1 << "\n";
        } else if (a > c && __gcd(a, c) == c && __gcd(b, d) == b) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }
}
