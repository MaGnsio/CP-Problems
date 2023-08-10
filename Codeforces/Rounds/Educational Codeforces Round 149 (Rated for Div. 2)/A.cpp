/**
 *    author:  MaGnsi0
 *    created: 25.05.2023 17:35:55
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
        if (n % k) {
            cout << 1 << "\n";
            cout << n << "\n";
        } else {
            cout << 2 << "\n";
            cout << n - 1 << " " << 1 << "\n";
        }
    }
}
