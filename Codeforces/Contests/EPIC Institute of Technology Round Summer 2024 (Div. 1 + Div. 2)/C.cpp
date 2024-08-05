/**
 *    author:  MaGnsi0
 *    created: 03.07.2024 20:50:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        vector<int> t(n);
        t[n - 1] = h[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            t[i] = max(h[i], t[i + 1] + 1);
        }
        int ans = t[0];
        cout << ans << "\n";
    }
}
