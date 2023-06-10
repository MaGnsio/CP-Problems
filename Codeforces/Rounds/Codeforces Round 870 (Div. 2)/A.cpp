/**
 *    author:  MaGnsi0
 *    created: 05.05.2023 17:36:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = -1;
        for (int i = 0; i <= n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                cnt += a[j] <= i;
            }
            if (cnt == n - i) {
                ans = i;
            }
        }
        cout << ans << "\n";
    }
}
