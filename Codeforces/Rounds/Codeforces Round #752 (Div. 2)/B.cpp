/**
 *    author:  MaGnsi0
 *    created: 31.10.2021 21:55:10
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
        bool ok = false;
        if (n % 2 == 0) {
            ok = true;
        } else {
            for (int i = 0; i + 1 < n; ++i) {
                if (a[i] >= a[i + 1]) {
                    ok = true;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
