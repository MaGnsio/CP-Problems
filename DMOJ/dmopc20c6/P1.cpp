/**
 *    author:  MaGnsi0
 *    created: 17.04.2023 22:07:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i < 2 * n; ++i) {
        a[i] = a[i - n];
    }
    for (int i = 1; i < 2 * n; ++i) {
        a[i] += a[i - 1];
    }
    int64_t sum = a[n - 1];
    for (int i = 0; i < n; ++i) {
        int j = i + n - 1;
        int64_t ans = sum;
        {
            int low = i, high = j - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                int64_t x = a[mid] - (i ? a[i - 1] : 0);
                if (2 * x <= sum) {
                    ans = min(ans, abs(x - (sum - x)));
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        {
            int low = i, high = j - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                int64_t x = a[mid] - (i ? a[i - 1] : 0);
                if (2 * x >= sum) {
                    ans = min(ans, abs(x - (sum - x)));
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        cout << ans;
        if (i != n - 1) { cout << " "; }
    }
    cout << "\n";
}
