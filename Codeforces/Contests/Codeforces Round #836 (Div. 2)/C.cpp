/**
 *    author:  MaGnsi0
 *    created: 29.11.2022 17:40:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        if (n % x) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 1);
        ans[0] = x, ans[n - 1] = 1;
        while (x < n) { 
            for (int i = 2 * x; i <= n; i += x) {
                if (n % i == 0) {
                    ans[x - 1] = i;
                    x = i;
                    break;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
