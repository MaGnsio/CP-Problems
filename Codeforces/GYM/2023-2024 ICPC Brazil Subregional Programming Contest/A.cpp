/**
 *    author:  MaGnsi0
 *    created: 13.09.2023 16:35:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int y; cin >> y;
        ans += x >= y;
    }
    cout << ans;
}
