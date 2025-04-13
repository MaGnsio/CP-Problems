/**
 *    author:  MaGnsi0
 *    created: 13.04.2025 20:23:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> ans(2 * n);
        vector<bool> done(2 * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x; cin >> x;
                ans[i + j + 1] = x; done[x - 1] = true;
            }
        }
        for (int x = 0; x < 2 * n; ++x) {
            if (!done[x]) { ans[0] = x + 1; }
        }
        for (int i = 0; i < 2 * n; ++i) {
            cout << ans[i] << (i == 2 * n - 1 ? "\n" : " ");
        }
    }
}
