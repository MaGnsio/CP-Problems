/**
 *    author:  MaGnsi0
 *    created: 03.11.2023 16:52:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t x; cin >> x;
    int64_t y; cin >> y;
    int64_t ans = 0;
    while (y < x) {
        if (x & 1) { x++, ans++; }
        x /= 2, ans++;
    }
    ans += y - x;
    cout << ans;
}
