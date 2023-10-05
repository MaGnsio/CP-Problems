/**
 *    author:  MaGnsi0
 *    created: 05.05.2023 18:10:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        bool ok = false;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                if (i <= m && i > 1) {
                    ok = true;
                }
                if (n / i <= m && n / i > 1) {
                    ok = true;
                }
            }
        }
        cout << (ok ? "NO" : "YES") << "\n";
    }
}
