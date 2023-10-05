/**
 *    author:  MaGnsi0
 *    created: 10/06/2021 16:23:51
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, sum = 0;
        cin >> n;
        vector<int> v(n);
        for (auto& x : v) {
            cin >> x;
            sum += x;
        }
        if (sum % n) {
            cout << -1 << "\n";
            continue;
        }
        int ans = 0;
        for (auto& x : v) {
            ans += (x > (sum / n));
        }
        cout << ans << "\n";
    }
}
