/**
 *    author:  MaGnsi0
 *    created: 16.10.2023 15:58:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n; cin >> n;
    int64_t m; cin >> m;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int64_t ans = 0;
    while (true) {
        int64_t need = 0, got = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] <= m) {
                m -= a[i];
                need += a[i];
                got++;
            }
        }
        if (got == 0) { break; }
        ans += got * (m / need) + got;
        m -= need * (m / need);
    }
    cout << ans;
}
