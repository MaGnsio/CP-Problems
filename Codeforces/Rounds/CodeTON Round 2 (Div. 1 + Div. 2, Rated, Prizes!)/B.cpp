/**
 *    author:  MaGnsi0
 *    created: 31.07.2022 16:02:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int l = a[0] - x, r = a[0] + x, ans = 0;
        for (int i = 1; i < n; ++i) {
            int nl = a[i] - x, nr = a[i] + x;
            if (r < nl || nr < l) {
                l = nl, r = nr, ans++;
            } else {
                l = max(l, nl);
                r = min(r, nr);
            }
        }
        cout << ans << "\n";
    }
}
