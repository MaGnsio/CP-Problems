/**
 *    author:  MaGnsi0
 *    created: 26.10.2024 15:01:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if ((n / 2) & 1) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> a(2 * n + 1), r(2 * n + 1, 0), c(n + 1, 0);
        for (int i = 1; i <= 2 * n; ++i) {
            if (r[i]) { continue; }
            for (int j = n; j >= 1; --j) {
                if (i + j > 2 * n || r[i + j] || c[j]) { continue; }
                a[i] = a[i + j] = j;
                r[i] = r[i + j] = 1; c[j] = 1;
                break;
            }
        }
        for (int i = 1; i <= 2 * n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
