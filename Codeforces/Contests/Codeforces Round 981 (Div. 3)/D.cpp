/**
 *    author:  MaGnsi0
 *    created: 24.10.2024 18:08:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        int ans = 0;
        set<int64_t> S; S.insert(0);
        for (int i = 0; i < n; ++i) {
            if (S.count(a[i])) {
                S.clear(); ans++;
            }
            S.insert(a[i]);
        }
        cout << ans << "\n";
    }
}
