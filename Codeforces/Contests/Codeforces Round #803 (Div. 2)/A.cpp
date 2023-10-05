/**
 *    author:  MaGnsi0
 *    created: 28.06.2022 16:34:04
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
        int ans;
        for (int i = 0; i < n; ++i) {
            int x = 0;
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                x ^= a[j];
            }
            if (x == a[i]) {
                ans = a[i];
                break;
            }
        }
        cout << ans << "\n";
    }
}
