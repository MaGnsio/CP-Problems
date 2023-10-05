/**
 *    author:  MaGnsi0
 *    created: 10/07/2021 16:57:44
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> a(n), b(m);
        for (auto& x : a) {
            cin >> x;
        }
        for (auto& x : b) {
            cin >> x;
        }
        bool ok = true;
        vector<int> ans(n + m);
        for (int i = 0, x = 0, y = 0; i < n + m; ++i) {
            if (x < n && a[x] <= k) {
                ans[i] = a[x];
                k += (a[x] == 0);
                x++;
            } else if (y < m && b[y] <= k) {
                ans[i] = b[y];
                k += (b[y] == 0);
                y++;
            } else {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << -1;
        } else {
            for (auto& x : ans) {
                cout << x << " ";
            }
        }
        cout << "\n";
    }
}
