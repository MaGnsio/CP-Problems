/**
 *    author:  MaGnsi0
 *    created: 19/06/2021 13:56:50
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    int l = 1, r = 100000, ans = 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (mid * (mid + 1) / 2 >= n) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
}
