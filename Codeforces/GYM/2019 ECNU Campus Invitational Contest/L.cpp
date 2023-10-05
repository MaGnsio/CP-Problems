/**
 *    author:  MaGnsi0
 *    created: 09.09.2023 22:48:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        vector<int> a(7);
        for (int i = 1; i <= 6; ++i) {
            cin >> a[i];
        }
        int ans = a[6] + a[5] + a[4] + a[3] / 2;
        a[1] = max(0, a[1] - a[5]), a[3] %= 2;
        int x = min(a[4], a[2]); 
        a[4] -= x, a[2] -= x;
        int y = min(a[4], (a[1] + 1) / 2);
        a[4] -= y, a[1] = max(0, a[1] - 2 * y);
        ans += a[2] / 3;
        a[2] %= 3;
        if (a[2] == 2) {
            ans++;
            a[1] = max(0, a[1] - 2);
            ans += a[3];
            a[1] = max(0, a[1] - 3 * a[3]);
            ans += (a[1] + 5) / 6;
        } else if (a[2] == 1) {
            if (a[3] == 1) {
                ans++;
                a[1] = max(0, a[1] - 1);
                ans += (a[1] + 5) / 6;
            } else {
                ans++;
                a[1] = max(0, a[1] - 4);
                ans += (a[1] + 5) / 6;
            }
        } else {
            if (a[3] == 1) {
                ans++;
                a[1] = max(0, a[1] - 3);
                ans += (a[1] + 5) / 6;
            } else {
                ans += (a[1] + 5) / 6;
            }
        }
        cout << ans << "\n";
    }
}
