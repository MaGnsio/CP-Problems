/**
 *    author:  MaGnsi0
 *    created: 17.05.2023 17:44:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t m, n;
        cin >> m >> n;
        if (m == n) {
            cout << "YES\n";
        } else if (m < n) {
            cout << "NO\n";
        } else {
            int64_t unit = m;
            while (unit % 2 == 0) { unit /= 2; }
            cout << (n % unit == 0 ? "YES" : "NO") << "\n";
        }
    }
}
