/**
 *    author:  MaGnsi0
 *    created: 13.08.2022 16:32:41
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
        vector<int> ans(n);
        if (n & 1) {
            ans[0] = 1;
            for (int i = 2; i <= n; i += 2) {
                ans[i - 1] = i + 1;
                ans[i] = i;
            }
        } else {
            for (int i = 1; i <= n; i += 2) {
                ans[i - 1] = i + 1;
                ans[i] = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
