/**
 *    author:  MaGnsi0
 *    created: 25.11.2023 22:10:54
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
        ans += x >= m;
    }
    cout << ans;
}
