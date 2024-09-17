/**
 *    author:  MaGnsi0
 *    created: 17.09.2024 01:35:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int> a(2 * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i + j]++;
            }
        }
        sort(a.rbegin(), a.rend());
        int ans = 0;
        for (int i = 0; i < 2 * n && k > 0; ++i) {
            int take = min(k, a[i]);
            ans++; k -= take;
        }
        cout << ans << "\n";
    }
}
