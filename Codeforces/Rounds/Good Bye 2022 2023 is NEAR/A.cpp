/**
 *    author:  MaGnsi0
 *    created: 30.12.2022 16:36:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int64_t> a(n), b(m);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < m; ++i) {
            sort(a.begin(), a.end());
            a[0] = b[i];
        }
        int64_t ans = accumulate(a.begin(), a.end(), int64_t(0));
        cout << ans << "\n";
    }
}
