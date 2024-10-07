/**
 *    author:  MaGnsi0
 *    created: 07.10.2024 19:55:07
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
        sort(a.begin(), a.end());
        int ans = (a[0] + a[1]) / 2;
        for (int i = 2; i < n; ++i) {
            ans = (ans + a[i]) / 2;
        }
        cout << ans << "\n";
    }
}
