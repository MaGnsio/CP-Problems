/**
 *    author:  MaGnsi0
 *    created: 24.05.2023 17:37:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, k;
        cin >> n >> k;
        if (n / 2 >= k) {
            int64_t x = (n + 1) / 2 - k;
            cout << (x % 2 == 0 ? "YES" : "NO") << "\n";
        } else {
            int64_t x = 3 * (k - n / 2) + n / 2;
            cout << (x <= (n + 1) / 2 && x % 2 == 0 ? "YES" : "NO") << "\n"; 
        }
    }
}
