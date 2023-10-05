/**
 *    author:  MaGnsi0
 *    created: 20.03.2023 02:18:16
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
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (a[0] != 1) {
            cout << "NO\n";
            continue;
        }
        bool ok = true;
        int64_t sum = a[0];
        for (int i = 1; i < n; ++i) {
            ok &= a[i] <= sum;
            sum += a[i];
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
