/**
 *    author:  MaGnsi0
 *    created: 11.10.2022 17:01:15
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
        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }
        bool can_make = true;
        function<int(int, int, int, int)> solve = [&](int l, int r, int low, int high) {
            if (r - l + 1 == 2) {
                if (a[l - 1] == low && a[r - 1] == high) {
                    return 0;
                }
                if (a[l - 1] == high && a[r - 1] == low) {
                    return 1;
                }
                can_make = false;
                return 0;
            }
            int m = (l + r) / 2, mid = (low + high) / 2;
            bool left = true, right = true;
            for (int i = l - 1; i < m; ++i) {
                left &= (low <= a[i] && a[i] <= mid);
            }
            for (int i = m; i < r; ++i) {
                right &= (mid < a[i] && a[i] <= high);
            }
            if (left && right) {
                return solve(l, m, low, mid) + solve(m + 1, r, mid + 1, high);
            }
            left = true, right = true;
            for (int i = l - 1; i < m; ++i) {
                right &= (mid < a[i] && a[i] <= high);
            }
            for (int i = m; i < r; ++i) {
                left &= (low <= a[i] && a[i] <= mid);
            }
            if (left && right) {
                return solve(l, m, mid + 1, high) + solve(m + 1, r, low, mid) + 1;
            }
            can_make = false;
            return 0;
        };
        int ans = solve(1, n, 1, n);
        cout << (can_make ? ans : -1) << "\n";
    }
}
