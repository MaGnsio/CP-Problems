/**
 *    author:  MaGnsi0
 *    created: 19.09.2022 16:32:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, x, y;
        cin >> n >> x >> y;
        string a, b;
        cin >> a >> b;
        vector<int> c;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                c.push_back(i);
            }
        }
        int64_t m = (int)c.size();
        if (m & 1) {
            cout << -1 << "\n";
        } else if (m > 2) {
            cout << (m / 2) * y << "\n";
        } else if (m == 0) {
            cout << 0 << "\n";
        } else {
            if (c[0] + 1 != c[1]) {
                cout << y << "\n";
            } else {
                if (n <= 3) {
                    cout << x << "\n";
                } else {
                    cout << min(2 * y, x) << "\n";
                }
            }
        }
    }
}
