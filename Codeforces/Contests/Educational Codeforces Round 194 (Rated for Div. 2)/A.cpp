/**
 *    author:  MaGnsi0
 *    created: 10.09.2026 00:52:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int m = count(a.begin(), a.end(), 0);
        if (m < 2) {
            cout << "-1\n";
        } else if (a[0] == 0 && a[n - 1] == 0) {
            cout << "0\n";
        } else if (a[0] == 0 || a[n - 1] == 0) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
}
