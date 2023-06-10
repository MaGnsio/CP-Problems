/**
 *    author:  MaGnsi0
 *    created: 24.04.2023 17:03:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << "\n";
        } else if (n & 1) {
            cout << -1 << "\n";
        } else {
            vector<int> ans(n);
            for (int i = 0, j = n; i < n; i += 2, j -= 2) {
                ans[i] = j;
            }
            for (int i = 1, j = 1; i < n; i += 2, j += 2) {
                ans[i] = j;
            }
            for (int i = 0; i < n; ++i) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
    }
}
