/**
 *    author:  MaGnsi0
 *    created: 28.11.2023 21:45:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool allNeg = true;
        for (int i = 0; i < n; ++i) {
            allNeg = allNeg && a[i] <= 0;
        }
        if (allNeg) {
            sort(a.rbegin(), a.rend());
            cout << a[0] << "\n";
            continue;
        }
        int ans = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            if ((sum < 0) || (i && (abs(a[i]) & 1) == (abs(a[i - 1]) & 1))) {
                sum = a[i];
            } else {
                sum += a[i];
            }
            ans = max(ans, sum);
        }
        cout << ans << "\n";
    }
}
