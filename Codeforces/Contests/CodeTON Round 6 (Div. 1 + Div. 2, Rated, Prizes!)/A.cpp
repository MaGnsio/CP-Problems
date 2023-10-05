/**
 *    author:  MaGnsi0
 *    created: 18.09.2023 17:35:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k, x;
        cin >> n >> k >> x;
        if (k > min(x + 1, n)) {
            cout << -1 << "\n";
            continue;
        }
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            ans += i;
        }
        for (int i = k; i < n; ++i) {
            if (k == x) {
                ans += x - 1;
            } else {
                ans += x;
            }
        }
        cout << ans << "\n";
    }
}
