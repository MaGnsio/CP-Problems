/**
 *    author:  MaGnsi0
 *    created: 23.05.2022 16:43:23
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
        int m;
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            ans += b[i];
            ans %= n;
        }
        cout << a[ans] << "\n";
    }
}
