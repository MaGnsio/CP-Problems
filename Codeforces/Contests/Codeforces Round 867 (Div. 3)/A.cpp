/**
 *    author:  MaGnsi0
 *    created: 24.04.2023 16:36:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, t;
        cin >> n >> t;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int ans = -2;
        for (int i = 0; i < n; ++i) {
            if (a[i] + i <= t && (ans == -2 || b[i] > b[ans])) {
                    ans = i;
            }
        }
        cout << ans + 1 << "\n";
    }
}
