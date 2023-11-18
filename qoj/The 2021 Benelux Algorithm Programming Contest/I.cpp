/**
 *    author:  MaGnsi0
 *    created: 05.10.2023 16:32:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    iota(c.begin(), c.end(), 0);
    sort(c.begin(), c.end(), [&](int i, int j) {
            return b[i] < b[j];
        });
    function<bool(int64_t)> F = [&](int64_t x) {
        int64_t finished = 0;
        for (int j : c) {
            if (b[j] == -1) { continue; }
            finished += a[j];
            if (__int128(x) * b[j] < finished) {
                return false;
            }
        }
        return true;
    };
    int64_t low = 1, high = 1e15, ans = high;
    while (low <= high) {
        int64_t mid = low + (high - low) / 2;
        if (F(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}
