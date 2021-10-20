/**
 *    author:  MaGnsi0
 *    created: 04/10/2021 21:23:18
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b.begin(), b.end());
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if ((a[i] == b[i]) || (i >= x) || (n - 1 - i >= x)) {
                continue;
            }
            ok = false;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
