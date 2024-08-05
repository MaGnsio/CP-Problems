/**
 *    author:  MaGnsi0
 *    created: 08.06.2024 15:00:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        int y = min(m, x);
        m -= y, x -= y;
        ans += x == 0;
    }
    cout << ans;
}
