/**
 *    author:  MaGnsi0
 *    created: 31.10.2023 20:23:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int c; cin >> c;
    int t; cin >> t;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    function<bool(int)> F = [&](int x) {
        int sum = 0, y = 1;
        for (int i = 0; i < n; ++i) {
            if ((sum + a[i] + t - 1) / t > x) {
                if ((a[i] + t - 1) / t > x) { return false; }
                sum = a[i];
                y++;
            } else {
                sum += a[i];
            }
        }
        return y <= c;
    };
    int low = 0, high = 1e9, ans = high; 
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (F(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans;
}
