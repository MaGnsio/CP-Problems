/**
 *    author:  MaGnsi0
 *    created: 12.03.2022 19:14:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("primes.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << -1;
        } else if (n == 2) {
            cout << 30;
        } else if (n == 3) {
            cout << 120;
        } else {
            cout << 1;
            for (int i = 0; i < n - 3; ++i) {
                cout << 0;
            }
            cout << 20;
        }
        cout << "\n";
    }
}
