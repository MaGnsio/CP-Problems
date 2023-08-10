/**
 *    author:  MaGnsi0
 *    created: 27.07.2023 17:35:55
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
        b += c;
        if (a > b)  {
            cout << 2 * b + 1 << "\n";
        } else {
            cout << 2 * a - 1 << "\n";
        }
    }
}
