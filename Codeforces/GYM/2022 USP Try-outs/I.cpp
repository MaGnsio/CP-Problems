/**
 *    author:  MaGnsi0
 *    created: 02.06.2023 22:21:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t a, b;
        cin >> a >> b;
        int64_t ans = b;
        while (ans < 100000000000000000) { ans *= 10; }
        ans += a - (ans % a);
        cout << ans << "\n";
    }
}
