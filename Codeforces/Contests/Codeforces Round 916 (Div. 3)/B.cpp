/**
 *    author:  MaGnsi0
 *    created: 21.12.2023 15:19:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int> ans(n);
        for (int i = k + 1, j = n - k - 1; i < n; ++i, --j) {
            ans[i] = j;
        }
        for (int i = 0, j = n - k; i <= k; ++i, ++j) {
            ans[i] = j;
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
