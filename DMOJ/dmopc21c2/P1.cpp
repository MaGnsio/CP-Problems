/**
 *    author:  MaGnsi0
 *    created: 10.04.2023 22:42:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, h, p;
    cin >> n >> h >> p;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int64_t m = a[0];
    vector<int64_t> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] + (i ? b[i - 1] : 0);
    }
    int64_t ans = h * m;
    for (int64_t i = 0; i <= m; ++i) {
        int64_t x = i * h;
        int64_t low = 0, high = n - 1, j = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[mid] > i) {
                j = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (j != -1) {
            x += p * (b[j] - i * (j + 1));
        }
        ans = min(ans, x);
    }
    cout << ans << "\n";
}
