/**
 *    author:  MaGnsi0
 *    created: 08.01.2024 12:49:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n == 1) {
            cout << "z\n";
        } else if (n == 2) {
            cout << "yz\n";
        } else if (n == 3) {
            cout << "xyz\n";
        } else if (n % 2 == 0) {
            int k = n / 2;
            string a(k, 'a');
            string c(k - 1, 'a');
            cout << a << "b" << c << "\n";
        } else {
            int k = n / 2;
            string a(k, 'a');
            string d(k - 1, 'a');
            cout << a << "bc" << d << "\n";
        }
    }
}
