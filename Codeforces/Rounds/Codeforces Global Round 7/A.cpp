/**
 *    author:  MaGnsi0
 *    created: 12.02.2023 20:37:20
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
        if (n == 1) {
            cout << -1 << "\n";
        } else {
            string ans(n, '3');
            ans[0] = '4';
            cout << ans << "\n";
        }
    }
}
