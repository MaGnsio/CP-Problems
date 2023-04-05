/**
 *    author:  MaGnsi0
 *    created: 04.02.2023 10:11:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, m;
        cin >> n >> m;
        if (n == m) {
            cout << 0 << "\n";
            continue;
        }
        if (n > m) {
            swap(n, m);
        }
        int64_t ans = n * (n + 1) / 2 + m * (m + 1) / 2;
        if (ans & 1) {
            cout << -1 << "\n";
            continue;
        }
        ans /= 2;
        int64_t low = 0, high = m, remove = 0;
        while (low <= high) {
            int64_t mid = (low + high) / 2;
            int64_t sum = (m - mid) * (m - mid + 1) / 2;
            if (sum >= ans) {
                remove = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        int64_t sum = (m - remove) * (m - remove + 1) / 2;
        cout << remove + (sum != ans) << "\n";
    }
}
