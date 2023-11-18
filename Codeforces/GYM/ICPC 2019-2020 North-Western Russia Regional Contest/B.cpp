/**
 *    author:  MaGnsi0
 *    created: 04.10.2023 22:25:28
**/
#pragma GCC optimize("Ofast","O3")
#include <bits/stdc++.h>

using namespace std;

const double e = 9e-5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x = -15684849, y = x + 1;
    cin >> n; n--;
    cout << x << "\n";
    while (n) {
        if (sin(y) > sin(x) && sin(y) - sin(x) < e) {
            cout << y << "\n";
            x = y, n--;
        }
        y++;
    }
}
