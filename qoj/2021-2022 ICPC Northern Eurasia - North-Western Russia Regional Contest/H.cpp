/**
 *    author:  MaGnsi0
 *    created: 27.09.2023 18:30:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n;
        cin >> n;
        int64_t ans = n / 2;
        while (__gcd(n, ans) != 1) { ans--; }
        cout << ans << "\n";
    }
}
