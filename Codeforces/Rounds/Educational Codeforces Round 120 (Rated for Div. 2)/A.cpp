/**
 *    author:  MaGnsi0
 *    created: 27.12.2021 16:26:49
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
        if ((a == b && c % 2 == 0) || (b == c && a % 2 == 0) || (c == a && b % 2 == 0)) {
            cout << "YES";
        } else if ((a + b == c) || (b + c == a) || (c + a == b)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << "\n";
    }
}
