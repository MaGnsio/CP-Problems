/**
 *    author:  MaGnsi0
 *    created: 11.10.2023 20:32:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, k;
    cin >> n >> k;
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        int64_t x; cin >> x; ans += x;
    }
    ans = (ans < k ? 0 : ans - (k + 1) / 2);
    cout << ans;
}
