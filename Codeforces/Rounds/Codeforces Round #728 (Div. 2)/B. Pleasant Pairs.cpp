/**
 *    author:  MaGnsi0
 *    created: 25/06/2021 23:22:44
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, ans = 0;
        cin >> n;
        vector<int> p(2 * n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            p[x] = i;
        }
        for (int i = 1; i <= 2 * n; ++i) {
            if (!p[i]) {
                continue;
            }
            for (int j = 1; j * i <= 2 * n; ++j) {
                if (i != j && p[i] && p[j] && p[i] + p[j] == i * j) {
                    ans++;
                }
            }
        }
        cout << ans / 2 << "\n";
    }
}
