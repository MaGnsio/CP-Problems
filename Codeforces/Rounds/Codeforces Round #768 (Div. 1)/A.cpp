/**
 *    author:  MaGnsi0
 *    created: 06.02.2022 03:09:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (k == n - 1) {
            if (n == 4) {
                cout << "-1\n";
            } else {
                cout << n - 1 << " " << n - 2 << "\n"; //all bits except for the 0th one
                cout << n - 3 << " " << 1 << "\n"; //0th one
                cout << 0 << " " << 2 << "\n";
                for (int i = 3; i < n / 2; ++i) {
                    cout << i << " " << (~i & (n - 1)) << "\n";
                }
            }
        } else {
            vector<int> x(n / 2), y(n / 2);
            for (int i = 0; i < n / 2; ++i) {
                x[i] = i, y[i] = n - i - 1;
            }
            for (int i = 0; i < n / 2; ++i) {
                if (x[i] == k) {
                    swap(x[i], x[0]);
                    break;
                }
                if (y[i] == k) {
                    swap(y[i], x[0]);
                    break;
                }
            }
            int res = 0;
            for (int i = 0; i < n / 2; ++i) {
                res += (x[i] & y[i]);
            }
            if (res == k) {
                for (int i = 0; i < n / 2; ++i) {
                    cout << x[i] << " " << y[i] << "\n";
                }
            } else {
                cout << "-1\n";
            }
        }
    }
}
