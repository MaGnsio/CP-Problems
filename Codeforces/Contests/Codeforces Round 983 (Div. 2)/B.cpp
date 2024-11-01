/**
 *    author:  MaGnsi0
 *    created: 01.11.2024 16:42:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        if (n == 1) {
            cout << "1\n" << "1\n";
        } else if (n == 3) {
            if (k == 2) {
                cout << "1\n" << "1\n";
            } else {
                cout << -1 << "\n";
            }
        } else {
            if (k == 1 || k == n) {
                cout << -1 << "\n";
            } else if (((k - 1) & 1) && ((n - k) & 1)) {
                cout << 3 << "\n";
                cout << 1 << " " << k << " " << k + 1 << "\n";
            } else if (((k - 1) & 1) == ((n - k) & 1)) {
                cout << 3 << "\n";
                cout << 1 << " " << k - 1 << " " << k + 2 << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    }
}
