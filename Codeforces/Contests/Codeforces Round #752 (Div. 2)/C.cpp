/**
 *    author:  MaGnsi0
 *    created: 31.10.2021 22:25:04
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (i > 23) {
                break;
            }
            bool chk = false;
            for (int j = 2; j <= i + 2; ++j) {
                if (a[i] % j) {
                    chk = true;
                }
            }
            ok &= chk;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
