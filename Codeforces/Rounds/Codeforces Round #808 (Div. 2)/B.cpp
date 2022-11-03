/**
 *    author:  MaGnsi0
 *    created: 16.07.2022 16:33:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, l, r;
        cin >> n >> l >> r;
        vector<int64_t> ans(n, -1);
        for (int64_t i = 1; i <= n; ++i) {
            int64_t x = i * (r / i);
            if (x < l) {
                break;
            }
            ans[i - 1] = x;
        }
        if (ans[n - 1] != -1) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                cout << ans[i] << " ";
            }
        } else {
            cout << "NO";
        }
        cout << "\n";
    }
}
