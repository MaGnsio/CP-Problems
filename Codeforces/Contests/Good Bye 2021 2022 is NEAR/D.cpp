/**
 *    author:  MaGnsi0
 *    created: 30.12.2021 17:55:23
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int x;
        cin >> x;
        for (int i = 0; i < n; ++i) {
            a[i] -= x;
        }
        int res = 0;
        for (int i = 0, j = 0; i < n; i = j + 1, j++) {
            int sum = 0, mx = -1e7;
            for ( ; j < n; ++j) {
                sum += a[j];
                if (sum - mx < 0) {
                    break;
                }
                mx = max(mx, sum - a[j]);
            }
            res += (j - i);
        }
        cout << res << "\n";
    }
}
