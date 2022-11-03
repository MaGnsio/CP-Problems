/**
 *    author:  MaGnsi0
 *    created: 15.06.2022 06:35:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 1, cur_length = 1; i < n; ++i) {
            if (2 * a[i] <= a[i - 1]) {
                cur_length = 0;
            }
            cur_length++;
            ans += (cur_length >= k + 1);
        }
        cout << ans << "\n";
    }
}
