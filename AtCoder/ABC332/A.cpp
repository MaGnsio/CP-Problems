/**
 *    author:  MaGnsi0
 *    created: 10.12.2023 14:00:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, s, k;
    cin >> n >> s >> k;
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        int64_t x, y;
        cin >> x >> y;
        ans += x * y;
    }
    ans += (ans < s) * k;
    cout << ans;
}
