/**
 *    author:  MaGnsi0
 *    created: 10.07.2022 16:32:26
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
        int ans;
        for (int64_t i = 1; i <= n; i *= 10) {
            ans = (n - i);
        }
        cout << ans << "\n";
    }
}
