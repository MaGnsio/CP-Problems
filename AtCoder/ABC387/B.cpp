/**
 *    author:  MaGnsi0
 *    created: 04.01.2025 14:25:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x; cin >> x;
    int64_t ans = 0;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            ans += (i * j != x) * (i * j);
        }
    }
    cout << ans;
}
