/**
 *    author:  MaGnsi0
 *    created: 15.07.2024 22:06:05
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
            cout << 0 << "\n";
            continue;
        }
        int ans = 0;
        while (n) {
            if (n <= k) {
                n -= n;
            } else {
                n -= (k - 1);
            }
            ans++;
        }
        cout << ans << "\n";
    }
}
