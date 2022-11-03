/**
 *    author:  MaGnsi0
 *    created: 11.10.2022 16:47:14
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
        int ans = n;
        for (int k = 1; k <= n; ++k) {
            int sum = accumulate(a.begin(), a.begin() + k, 0);
            int thick = k, cur_length = 0, cur_sum = 0;
            for (int i = k; i < n; ++i) {
                cur_sum += a[i];
                cur_length++;
                if (cur_sum == sum) {
                    thick = max(thick, cur_length);
                    cur_length = cur_sum = 0;
                }
                if (cur_sum > sum) {
                    break;
                }
            }
            if (cur_sum == 0) {
                ans = min(ans, thick);
            }
        }
        cout << ans << "\n";
    }
}
