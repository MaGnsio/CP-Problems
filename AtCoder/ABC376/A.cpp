/**
 *    author:  MaGnsi0
 *    created: 19.10.2024 15:00:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int c; cin >> c;
    int ans = 0, last = -c;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x - last >= c) {
            ans++; last = x;
        }
    }
    cout << ans;
}
