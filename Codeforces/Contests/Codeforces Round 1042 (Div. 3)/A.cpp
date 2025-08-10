/**
 *    author:  MaGnsi0
 *    created: 10.08.2025 17:37:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int x = 0;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) {
                x += a[i] - b[i];
            }
        }
        cout << x + 1 << "\n";
    }
}
