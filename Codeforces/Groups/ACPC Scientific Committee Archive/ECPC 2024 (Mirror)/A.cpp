/**
 *    author:  MaGnsi0
 *    created: 29.07.2024 18:52:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n; cin >> n;
    int64_t x; cin >> x;
    int64_t y; cin >> y;
    cout << "? " << 1 << " " << n << endl;
    for (int i = 1; i <= n; ++i) {
        cout << i << endl;
    }
    int64_t sum; cin >> sum;
    sum -= x * n * (n + 1) / 2;
    int64_t ans = sum / (y - x);
    cout << "! " << ans << endl;
}
