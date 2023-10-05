/**
 *    author:  MaGnsi0
 *    created: 16/08/2021 19:07:42
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int ans;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (!i) {
                ans = x;
            } else {
                ans &= x;
            }
        }
        cout << ans << "\n";
    }
}
