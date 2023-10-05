/**
 *    author:  MaGnsi0
 *    created: 25.05.2022 19:34:24
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
        int sum = accumulate(a.begin(), a.end(), 0);
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            ok |= bool(sum - a[i] == (n - 1) * a[i]);
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
