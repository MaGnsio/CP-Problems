/**
 *    author:  MaGnsi0
 *    created: 28.02.2024 20:56:25
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
        int L = n, R = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i]) {
                L = min(L, i);
                R = max(R, i);
            }
        }
        int ans = 0;
        for (int i = L; i <= R; ++i) {
            ans += a[i] == 0;
        }
        cout << ans << "\n";
    }
}
