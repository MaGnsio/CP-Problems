/**
 *    author:  MaGnsi0
 *    created: 31.10.2021 21:47:52
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
        int ans = 0;
        for (int i = 0, j = 1; i < n; ++i) {
            ans += max(0, a[i] - j);
            j = max(a[i], j) + 1;
        }
        cout << ans << "\n";
    }
}
