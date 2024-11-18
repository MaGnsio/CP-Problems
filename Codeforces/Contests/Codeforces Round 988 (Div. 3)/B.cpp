/**
 *    author:  MaGnsi0
 *    created: 18.11.2024 19:10:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; mp[x]++;
        }
        for (auto& [x, f] : mp) {
            if ((n - 2) % x) { continue; }
            int y = (n - 2) / x;
            if (mp[y] - (y == x) > 0) {
                cout << x << " " << y << "\n";
                break;
            }
        }
    }
}
