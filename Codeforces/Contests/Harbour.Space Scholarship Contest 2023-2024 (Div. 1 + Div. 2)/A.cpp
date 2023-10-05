/**
 *    author:  MaGnsi0
 *    created: 26.08.2023 17:36:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int x, y, n;
        cin >> x >> y >> n;
        bool ok = true;
        vector<int> a(n);
        a[n - 1] = y;
        for (int i = n - 2, j = 1; i >= 0; --i, ++j) {
            if (i) {
                a[i] = a[i + 1] - j;
            } else {
                if (a[i + 1] - x >= j) {
                    a[0] = x;
                } else {
                    ok = false;
                }
            }
            if (a[i] < 0) {
                ok = false;
            }
        }
        if (ok) {
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            }
        } else {
            cout << -1;
        }
        cout << "\n";
    }
}
