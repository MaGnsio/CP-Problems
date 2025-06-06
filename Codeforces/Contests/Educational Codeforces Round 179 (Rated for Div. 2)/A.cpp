/**
 *    author:  MaGnsi0
 *    created: 06.06.2025 20:59:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int ans = 2;
        vector<int> c = {0, 1, 1};
        while (c[0] != n || c[1] != n || c[2] != n) {
            sort(c.begin(), c.end());
            if (c[1] == c[2]) { c[0] = min(2 * c[1] + 1, n); }
            else { c[0] = c[2]; }
            ans++;
        }
        cout << ans << "\n";
    }
}
