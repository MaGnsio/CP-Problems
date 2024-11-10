/**
 *    author:  MaGnsi0
 *    created: 10.11.2024 16:31:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int k; cin >> k;
        int n; cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; x--;
            int y; cin >> y;
            a[x] += y;
        }
        sort(a.rbegin(), a.rend());
        int ans = accumulate(a.begin(), a.begin() + min(n, k), 0);
        cout << ans << "\n";
    }
}
