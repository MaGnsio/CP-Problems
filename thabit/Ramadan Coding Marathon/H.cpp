/**
 *    author:  MaGnsi0
 *    created: 12.04.2022 22:00:14
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
        int64_t ans = n * n * (n - 1) / 2 + n * (n + 1) / 2;
        cout << ans << "\n";
    }
}
