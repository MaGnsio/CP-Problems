/**
 *    author:  MaGnsi0
 *    created: 29.04.2024 17:36:22
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
            cin >> a[i]; a[i]--;
        }
        int ans = 3;
        for (int i = 0; i < n; ++i) {
            if (a[a[i]] == i) {
                ans = 2;
            }
        }
        cout << ans << "\n";
    }
}
