/**
 *    author:  MaGnsi0
 *    created: 15.11.2024 14:52:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if ((n & 1) && (n < 27)) {
            cout << -1 << "\n";
            continue;
        }
        if (n % 2 == 0) {
            for (int i = 0, j = 1; i < n; i += 2, ++j) {
                cout << j << " " << j << " ";
            }
            cout << "\n";
            continue;
        }
        int j = 4;
        vector<int> ans(n + 1, -1);
        ans[1] = ans[10] = ans[26] = 1;
        ans[23] = ans[27] = 2;
        ans[24] = ans[25] = 3;
        for (int i = 2; i < 10; i += 2) {
            ans[i] = ans[i + 1] = j++;
        }
        for (int i = 11; i < 23; i += 2) {
            ans[i] = ans[i + 1] = j++;
        }
        for (int i = 28; i <= n; i += 2) {
            ans[i] = ans[i + 1] = j++;
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
