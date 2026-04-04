/**
 *    author:  MaGnsi0
 *    created: 04.04.2026 16:36:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n = 7;
        vector<int> a(n);
        int ans = -1e5, sum = 0;
        for (int& x : a) { cin >> x; x *= -1; sum += x; }
        for (int& x : a) { ans = max(ans, sum - 2 * x); }
        cout << ans << "\n";
    }
}
