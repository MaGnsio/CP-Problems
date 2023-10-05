/**
 *    author:  MaGnsi0
 *    created: 24.08.2023 17:45:50
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
        bool ok = true;
        vector<int> b(n + 1);
        for (int i = 0; i < n; ++i) {
            if (a[i] > n) { ok = false; continue; }
            b[0]++, b[a[i]]--;
        }
        for (int i = 1; i <= n; ++i) {
            b[i] += b[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            ok = ok && b[i] == a[i];
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
