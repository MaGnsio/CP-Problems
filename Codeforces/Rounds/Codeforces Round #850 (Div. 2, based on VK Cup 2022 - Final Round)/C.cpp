/**
 *    author:  MaGnsi0
 *    created: 05.02.2023 14:20:13
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
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int64_t ans = 0, cur_min = 1;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= cur_min) {
                ans += a[i] - cur_min;
                cur_min++;
            }
        }
        cout << ans << "\n";
    }
}
