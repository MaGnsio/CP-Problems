/**
 *    author:  MaGnsi0
 *    created: 14.04.2023 22:17:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, m;
    cin >> n >> m;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }
    int ans = n + 1;
    for (int i = 0; i < n; ++i) {
        int low = 0, high = i, j = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[i] - (mid ? a[mid - 1] : 0) >= m) {
                j = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (j != -1) {
            ans = min(ans, i - j + 1);
        }
    }
    cout << (ans == n + 1 ? -1 : ans);
}
