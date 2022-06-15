/**
 *    author:  MaGnsi0
 *    created: 06.05.2022 16:34:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, neg = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            neg += (a[i] < 0);
        }
        bool ok = true;
        for (int i = 1; i < neg; ++i) {
            ok &= bool(abs(a[i]) <= abs(a[i - 1]));
        }
        for (int i = neg + 1; i < n; ++i) {
            ok &= bool(abs(a[i]) >= abs(a[i - 1]));
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
