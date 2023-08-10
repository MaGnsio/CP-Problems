/**
 *    author:  MaGnsi0
 *    created: 18.06.2023 11:10:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string L, R;
        cin >> L >> R;
        int64_t n = (int)R.size(), ans = 0;
        reverse(L.begin(), L.end());
        while (L.size() < R.size()) {
            L += '0';
        }
        reverse(L.begin(), L.end());
        bool differed = false;
        for (int i = 0; i < n; ++i) {
            if (differed) {
                ans += 9;
            } else {
                ans += abs(R[i] - L[i]);
                differed |= L[i] != R[i];
            }
        }
        cout << ans << "\n";
    }
}
