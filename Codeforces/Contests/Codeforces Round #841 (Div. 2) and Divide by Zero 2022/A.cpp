/**
 *    author:  MaGnsi0
 *    created: 27.12.2022 16:37:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n;
        cin >> n;
        int64_t ans = 1;
        for (int i = 0; i < n; ++i) {
            int64_t x;
            cin >> x;
            ans *= x;
        }
        ans += n - 1;
        cout << 2022 * ans << "\n";
    }
}
