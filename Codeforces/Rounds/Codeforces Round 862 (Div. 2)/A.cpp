/**
 *    author:  MaGnsi0
 *    created: 02.04.2023 16:36:34
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
        int xor_sum = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            xor_sum ^= x;
        }
        if ((xor_sum == 0) || (n & 1)) {
            cout << xor_sum << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}
