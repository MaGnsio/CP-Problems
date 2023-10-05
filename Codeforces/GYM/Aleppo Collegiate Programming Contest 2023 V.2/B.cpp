/**
 *    author:  MaGnsi0
 *    created: 29.08.2023 14:03:47
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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int g1 = 0, g2 = 0;
        for (int i = 0; i < n; ++i) {
            g1 = __gcd(g1, a[i]);
            g2 = __gcd(g2, b[i]);
        }
        int g = __gcd(g1, g2);
        g1 /= g, g2 /= g;
        cout << (g1 != 1) + (g2 != 1) << "\n";
    }
}
