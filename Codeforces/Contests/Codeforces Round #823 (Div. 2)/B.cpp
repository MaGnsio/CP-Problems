/**
 *    author:  MaGnsi0
 *    created: 25.09.2022 16:34:10
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
        vector<int> c(2 * n);
        for (int i = 0; i < n; ++i) {
            c[2 * i] = a[i] - b[i];
            c[2 * i + 1] = a[i] + b[i];
        }
        sort(c.begin(), c.end());
        cout << fixed << setprecision(1) << 1.0 * (c[2 * n - 1] + c[0]) / 2.0 << "\n";
    }
}
