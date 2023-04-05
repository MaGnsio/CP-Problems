/**
 *    author:  MaGnsi0
 *    created: 29.11.2022 18:04:32
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
        int64_t x = 0, cnt = count(a.begin(), a.end(), 0);
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                x += cnt;
            } else {
                cnt--;
            }
        }
        int64_t ans = x, cnt1 = 0;
        cnt = count(a.begin(), a.end(), 0);
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                cnt--;
                ans = max(ans, x - cnt1 + cnt);
            } else {
                ans = max(ans, x - cnt + cnt1);
                cnt1++;
            }
        }
        cout << ans << "\n";
    }
}
