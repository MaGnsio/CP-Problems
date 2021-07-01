/**
 *    author:  MaGnsi0
 *    created: 04/06/2021 19:02:36
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long n, x, y;
    cin >> n >> x >> y;
    long long l = 1, r = min(x, y) * n, ans;
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        long long k = (mid / x) + (mid / y);
        if (k >= n) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
}
