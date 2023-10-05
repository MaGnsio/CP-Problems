/**
 *    author:  MaGnsi0
 *    created: 25.09.2023 17:35:51
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
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (ans + 1 == a[i]) {
                ans = ans + 2;
            } else {
                ans = ans + 1;
            }
        }
        cout << ans << "\n";
    }
}
