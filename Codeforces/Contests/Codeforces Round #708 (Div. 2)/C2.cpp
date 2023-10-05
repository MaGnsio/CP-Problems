/**
 *    author:  MaGnsi0
 *    created: 18.11.2021 15:33:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < k - 3; ++i) {
            cout << 1 << " ";
        }
        n -= (k - 3);
        if (n % 3 == 0) {
            cout << n / 3 << " " << n / 3 << " " << n / 3 << "\n";
        } else if (n % 4 == 0) {
            cout << n / 2 << " " << n / 4 << " " << n / 4 << "\n";
        } else if (n % 2 == 0) {
            cout << n / 2 - 1 << " " << n / 2 - 1 << " " << 2 << "\n";
        } else {
            cout << 1 << " " << n / 2 << " " << n / 2 << "\n";
        }
    }
}
