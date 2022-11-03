/**
 *    author:  MaGnsi0
 *    created: 29.09.2022 16:42:22
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
        bool mult = false;
        vector<int> b(n);
        b[0] = a[0];
        for (int i = 1; i < n; ++i) {
            if (a[i] && b[i - 1] - a[i] >= 0) {
                mult = true;
                break;
            }
            b[i] = b[i - 1] + a[i];
        }
        if (mult) {
            cout << -1 << "\n";
        } else {
            for (int i = 0; i < n; ++i) {
                cout << b[i] << " ";
            }
            cout << "\n";
        }
    }
}
