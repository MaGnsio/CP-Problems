/**
 *    author:  MaGnsi0
 *    created: 12.12.2022 19:27:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n = 2, m;
        cin >> m;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int j = 0;
        while (j < m && a[0][j] == a[1][j]) { j++; }
        bool ok = true;
        while (j < m) {
            int i = j + 1;
            while (i < m && a[0][i] == a[1][i]) { i++; }
            if (i >= m) { break; }
            int x = i - j - 1;
            if ((x & 1) ^ (a[0][i] != a[0][j])) { ok = false; break; }
            j = i;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
