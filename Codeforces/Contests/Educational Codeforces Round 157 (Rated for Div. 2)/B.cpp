/**
 *    author:  MaGnsi0
 *    created: 24.11.2023 14:37:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        cout << a[n - 1] - a[0] + a[2 * n - 1] - a[n] << "\n";
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " " << a[n + i] << "\n";
        }
    }
}
