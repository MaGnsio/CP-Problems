/**
 *    author:  MaGnsi0
 *    created: 07.06.2023 03:38:38
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
        sort(a.begin(), a.end());
        function<bool(int)> F = [&](int x) {
            int last = a[0], cnt = 1;
            for (int i = 0; i < n; ++i) {
                if ((a[i] - last + 1) / 2 > x) {
                    last = a[i];
                    cnt++;
                }
            }
            return cnt <= 3;
        };
        int low = 0, high = a[n - 1], ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (F(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
