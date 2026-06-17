/**
 *    author:  MaGnsi0
 *    created: 18.06.2026 00:01:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> h(n);
        for (int& x : h) { cin >> x; }
        sort(h.begin(), h.end());
        int ans = h[n - 1] - h[0] + 1;
        cout << ans << "\n";
    }
}
