/**
 *    author:  MaGnsi0
 *    created: 22.11.2024 17:45:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int x; cin >> x; x--;
        int y; cin >> y; y--;
        vector<int> ans(n);
        for (int i = y - 1; i >= 0; --i) {
            ans[i] = ((y - i - 1) & 1 ? 1 : -1);
        }
        for (int i = y; i <= x; ++i) {
            ans[i] = 1;
        }
        for (int i = x + 1; i < n; ++i) {
            ans[i] = ((i - x - 1) & 1 ? 1 : -1);
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
