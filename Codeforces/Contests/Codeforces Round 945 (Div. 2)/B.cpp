/**
 *    author:  MaGnsi0
 *    created: 19.05.2024 16:41:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 1;
        for (int bit = 0; bit <= 30; ++bit) {
            for (int i = 0, j = -1; i < n; ++i) {
                if (a[i] >> bit & 1) {
                    ans = max(ans, i - j);
                    j = i;
                }
                if (i == n - 1 && j != -1) {
                    ans = max(ans, i - j + 1);
                }
            }
        }
        cout << ans << "\n";
    }
}
