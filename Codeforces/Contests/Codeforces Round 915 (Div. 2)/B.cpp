/**
 *    author:  MaGnsi0
 *    created: 18.12.2023 14:07:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n - 1; ++i) {
            int u; cin >> u; a[--u]++;
            int v; cin >> v; a[--v]++;
        }
        int ans = (count(a.begin(), a.end(), 1) + 1) / 2;
        cout << ans << "\n";
    }
}
