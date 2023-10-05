/**
 *    author:  MaGnsi0
 *    created: 08.07.2022 22:26:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
            a[i]--;
        }
        vector<int> cnt(n, 0);
        for (int i = 0; i < m; ++i) {
            cnt[a[i]]++;
        }
        int low = 0, high = 2 * (m + n - 1) / n, ans;
        while (low <= high) {
            int mid = (low + high) / 2;
            int needed_time = 0;
            int spare_time = 0;
            for (int i = 0; i < n; ++i) {
                if (cnt[i] == mid) {
                    continue;
                } else if (cnt[i] < mid) {
                    spare_time += (mid - cnt[i]) / 2;
                } else {
                    needed_time += (cnt[i] - mid);
                }
            }
            if (needed_time <= spare_time) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
