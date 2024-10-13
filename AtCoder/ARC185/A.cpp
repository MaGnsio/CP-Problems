/**
 *    author:  MaGnsi0
 *    created: 13.10.2024 15:05:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t m; cin >> m;
        int64_t x = n % m * (n + 1) % m;
        cout << (0 < x && x <= n ? "Bob" : "Alice") << "\n";
    }
}
