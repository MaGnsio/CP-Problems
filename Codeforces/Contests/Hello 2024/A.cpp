/**
 *    author:  MaGnsi0
 *    created: 06.01.2024 16:36:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t x; cin >> x;
        int64_t y; cin >> y;
        cout << ((x + y) & 1 ? "Alice" : "Bob") << "\n";
    }
}
