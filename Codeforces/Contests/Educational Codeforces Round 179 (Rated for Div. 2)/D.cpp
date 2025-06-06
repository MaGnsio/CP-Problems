/**
 *    author:  MaGnsi0
 *    created: 06.06.2025 21:34:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            int x = i & 1 ? m - 1 - i / 2 : i / 2;
            int y = m - x - 1;
            for (int _ = 0; _ < 3; ++_) {
                cout << a[x] << " " << a[y] << " ";
            }
            cout << "\n";
        }
    }
}
