/**
 *    author:  MaGnsi0
 *    created: 13.10.2021 16:27:20
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
        sort(a.begin(), a.end());
        int g = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == a[0]) {
                continue;
            }
            g = gcd(abs(a[i] - a[0]), g);
        }
        cout << (a[0] == a[n - 1] ? -1 : g) << "\n";
   }
}
