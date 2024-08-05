/**
 *    author:  MaGnsi0
 *    created: 23.06.2024 17:51:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int X[3];
        for (int i = 0; i < 3; ++i) {
            cin >> X[i];
        }
        int ans = INT_MAX;
        for (int i = 0; i <= 10; ++i) {
            int val = 0;
            for (int j = 0; j < 3; ++j) {
                val += abs(X[j] - i);
            }
            ans = min(ans, val);
        }
        cout << ans << "\n";
    }
}
