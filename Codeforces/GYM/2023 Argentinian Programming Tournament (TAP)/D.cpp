/**
 *    author:  MaGnsi0
 *    created: 21.09.2023 10:54:49
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    function<bool(int64_t)> F = [&](int64_t x) {
        int64_t rem = 0;
        for (int i = 0; i < n; ++i) {
            if (rem + b[i] < x * a[i]) {
                return false;
            }
            rem = rem + b[i] - x * a[i];
        }
        return true;
    };
    int64_t low = 0, high = OO, ans = 0;
    while (low <= high) {
        int64_t mid = (low + high) / 2;
        if (F(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans;
}
