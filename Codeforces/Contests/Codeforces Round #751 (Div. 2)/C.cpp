/**
 *    author:  MaGnsi0
 *    created: 11.11.2021 17:03:33
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
        vector<int> a(n), f(31, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int j = 0; j <= 30; ++j) {
                f[j] += ((a[i] >> j) & 1);
            }
        }
        int g = 0;
        for (int i = 0; i < 30; ++i) {
            g = __gcd(g, f[i]);
        }
        for (int i = 1; i <= n; ++i) {
            if (g % i == 0) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
}
