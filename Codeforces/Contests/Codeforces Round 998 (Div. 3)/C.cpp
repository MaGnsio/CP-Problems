/**
 *    author:  MaGnsi0
 *    created: 26.01.2025 22:13:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int> a(k + 1, 0);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (x > k) { continue; }
            a[x]++;
        }
        int ans = 0;
        for (int i = 0; i <= k; ++i) {
            ans += min(a[i], a[k - i]);
        }
        cout << ans / 2 << "\n";
    }
}
