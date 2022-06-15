/**
 *    author:  MaGnsi0
 *    created: 03.04.2022 21:59:37
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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, b[i] - a[i]);
        }
        cout << ans << "\n";
    }
}
