/**
 *    author:  MaGnsi0
 *    created: 10.11.2024 16:27:44
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
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            ok = ok && (abs(a[i] - a[i - 1]) == 5 || abs(a[i] - a[i - 1]) == 7);
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
