/**
 *    author:  MaGnsi0
 *    created: 16.12.2021 15:20:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n & 1) {
            for (int i = 4; n - i > 3; i += 2) {
                if (__gcd(n - i, i - 1) == 1) {
                    cout << n - i << " " << i - 1 << " " << 1 << "\n";
                    break;
                }
            }
        } else {
            cout << n / 2 - 1 << " " << n / 2 << " " << 1 << "\n";
        }
    }
}
