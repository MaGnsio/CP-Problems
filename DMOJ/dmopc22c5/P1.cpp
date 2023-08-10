/**
 *    author:  MaGnsi0
 *    created: 26.07.2023 19:57:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n;
    cin >> n;
    int64_t ans = 0;
    for (int64_t ones = 1; ones <= n - 2; ++ones) {
        ans = max(ans, (ones * (ones - 1) / 2) * ((n - ones) / 2));
    }
    cout << ans;
}
