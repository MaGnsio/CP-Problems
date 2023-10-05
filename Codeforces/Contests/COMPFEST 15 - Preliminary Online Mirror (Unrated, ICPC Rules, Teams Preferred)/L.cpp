/**
 *    author:  MaGnsi0
 *    created: 03.09.2023 21:35:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int ans = 1;
    int64_t sum = 0;
    vector<int> done;
    function<int64_t(int, int, int)> G = [&](int x, int y, int k) {
        if (x >= n || done[y % k] <= y) { return int64_t(0); }
        int low = 0, high = min(n - x, (n - y) / k), z = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (x + mid < y + mid * k) {
                z = mid, high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        x = x + max(z, 0), y = y + max(z, 0) * k;
        if (done[y % k] <= y) { return int64_t(0); }
        done[y % k] = min(done[y % k], y);
        int t = (n - y + k) / k;
        int64_t add = (z != -1 ? 1LL * y * t + 1LL * k * t * (t - 1) / 2 : 0);
        return G(x + t, (y + t * k) % n, k) + add;
    };
    for (int k = 2; k <= m; ++k) {
        done = vector<int>(k, n + 1);
        int64_t val = G(1, k, k);
        if (val > sum) { ans = k, sum = val; }
    }
    cout << ans;
}
