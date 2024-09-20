#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t sum = 0;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        int64_t ans = sum;
        for (int x = 0; x <= a[0]; ++x) {
            for (int y = a[n - 1]; y <= sum - x; ++y) {
                vector<int64_t> b = {x, y, (sum - x - y) / (n - 2), (sum - x - y + n - 3) / (n - 2)};
                sort(b.begin(), b.end());
                ans = min(ans, b[3] - b[0]);
            }
        }
        cout << ans << "\n";
    }
}
