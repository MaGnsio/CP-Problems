/**
 *    author:  MaGnsi0
 *    created: 05.05.2024 14:06:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 1; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> ans(n, 1000);
        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i - 1] + a[i];
        }
        for (int i = 1; i < n; ++i) {
            assert(a[i] == ans[i] % ans[i - 1]);
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
