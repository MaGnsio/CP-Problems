/**
 *    author:  MaGnsi0
 *    created: 14.12.2021 22:13:38
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
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        long long g1 = 0, g2 = 0;
        for (int i = 0; i < n; i += 2) {
            g1 = __gcd(g1, a[i]);
        }
        for (int i = 1; i < n; i += 2) {
            g2 = __gcd(g2, a[i]);
        }
        bool ok1 = true, ok2 = true;
        for (int i = 0; i < n; i += 2) {
            if (g2 && a[i] % g2 == 0) {
                ok2 = false;
            }
        }
        for (int i = 1; i < n; i += 2) {
            if (g1 && a[i] % g1 == 0) {
                ok1 = false;
            }
        }
        cout << (ok1 && g1 ? g1 : (ok2 ? g2 : 0LL)) << "\n";
    }
}
