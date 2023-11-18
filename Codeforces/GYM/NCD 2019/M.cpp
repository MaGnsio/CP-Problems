/**
 *    author:  MaGnsi0
 *    created: 15.10.2023 21:29:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int B1, P1, B2, P2;
        cin >> B1 >> P1 >> B2 >> P2;
        if (B1 == 0 && B2 == 0) {
            cout << "Lazy\n";
        } else if (B1 == 0) {
            cout << "Congrats\n";
        } else if (B2 == 0) {
            cout << "HaHa\n";
        } else {
            double x = 1.0 * P1 * log(B1);
            double y = 1.0 * P2 * log(B2);
            if (x < y - 1e-9) {
                cout << "Congrats\n";
            } else if (x - 1e-9 > y) {
                cout << "HaHa\n";
            } else {
                cout << "Lazy\n";
            }
        }
    }
}
