/**
 *    author:  MaGnsi0
 *    created: 18.10.2024 19:15:50
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
        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }
        vector<int> left(n), right(n);
        for (int i = 0; i + 1 < n; ++i) {
            left[i] = a[i] < a[i + 1];
        }
        for (int i = 1; i < n; ++i) {
            right[i] = a[i] < a[i - 1];
        }
        for (int i = 1; i < n; ++i) {
            left[i] += left[i - 1];
            right[i] += right[i - 1];
        }
        function<int(int)> get_lefts = [&](int i) {
            //j : j < i && a[j] < a[j + 1]
            int low = 0, high = i - 1, j = i;
            while (low <= high) {
                int mid = (low + high) / 2;
                int sum = left[i - 1] - (mid ? left[mid - 1] : 0);
                int length = i - mid;
                if (sum == length) {
                    j = mid; high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return j;
        };
        function<int(int)> get_rights = [&](int i) {
            //j : j > i && a[j] < a[j - 1]
            int low = i + 1, high = n - 1, j = i;
            while (low <= high) {
                int mid = (low + high) / 2;
                int sum = right[mid] - right[i];
                int length = mid - i;
                if (sum == length) {
                    j = mid; low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            return j;
        };
        int64_t ans = 0;
        for (int i = 1; i + 1 < n; ++i) {
            int64_t x = i - get_lefts(i);
            int64_t y = get_rights(i) - i;
            ans += x * y;
        }
        cout << ans << "\n";
    }
}
