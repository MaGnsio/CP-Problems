/**
 *    author:  MaGnsi0
 *    created: 17.06.2024 16:08:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t k; cin >> k;
        int64_t max_value = 0;
        for (int i = 1; i <= n; ++i) {
            max_value += abs(n - 2 * i + 1);
        }
        if ((k & 1) || (k > max_value)) {
            cout << "No\n";
            continue;
        }
        vector<int> ans(n);
        int low = 1, high = n;
        while (low <= high) {
            if (2 * (high - low) > k) {
                ans[low - 1] = low;
                low++;
            } else {
                ans[low - 1] = high;
                ans[high - 1] = low;
                k -= 2 * (high - low);
                low++, high--;
            }
        }
        cout << "Yes\n";
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
