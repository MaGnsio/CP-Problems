/**
 *    author:  MaGnsi0
 *    created: 18.08.2024 23:41:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int nimber = 0;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; mp[x]++;
        nimber ^= x;
    }
    if (nimber) {
        cout << -1;
        return 0;
    }
    int ans = 0;
    for (auto [x, c] : mp) {
        if (c & 1) {
            ans = max(ans, x - 1);
        }
    }
    cout << ans;
}
