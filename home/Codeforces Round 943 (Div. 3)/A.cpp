/**
 *    author:  MaGnsi0
 *    created: 05.05.2024 14:00:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int ans = 0, sum = 0;
        for (int i = 1; i < n; ++i) {
            if (__gcd(n, i) + i > sum) {
                ans = i;
                sum = __gcd(n, i) + i;
            }
        }
        cout << ans << "\n";
    }
}
