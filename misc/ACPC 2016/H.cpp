#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, k;
        cin >> n >> k;
        if (n == 0) {
            cout << 0;
            if (T) { cout << "\n"; }
            continue;
        }
        int64_t low = 0, high = n - 1, ans; 
        while (low <= high) {
            int64_t mid = (low + high) / 2;
            int64_t x = (n - 1) / (n - mid);
            if (x <= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans;
        if (T) { cout << "\n"; }
    }
}
