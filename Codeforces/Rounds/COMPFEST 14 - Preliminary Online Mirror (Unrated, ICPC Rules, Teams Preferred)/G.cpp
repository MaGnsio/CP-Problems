/**
 *    author:  MaGnsi0
 *    created: 24.07.2023 13:30:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n;
    cin >> n;
    int64_t low = 3, high = 1e10, ans = -1;
    while (low <= high) {
        int64_t mid = low + (high - low) / 2;
        int64_t k = mid - (mid / 4) - (mid % 4 >= 2) - (mid >= 4) - 1;
        if (k >= n) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans;
}
