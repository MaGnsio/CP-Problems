/**
 *    author:  MaGnsi0
 *    created: 27.07.2023 06:15:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            ans += a[i];
        }
        cout << ans << "\n";
    }
}
