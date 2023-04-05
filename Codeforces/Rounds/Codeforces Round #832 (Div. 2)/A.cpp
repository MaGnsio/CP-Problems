/**
 *    author:  MaGnsi0
 *    created: 04.11.2022 16:36:41
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
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ans += x;
        }
        cout << abs(ans) << "\n";
    }
}
