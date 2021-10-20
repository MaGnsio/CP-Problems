/**
 *    author:  MaGnsi0
 *    created: 18/07/2021 13:22:53
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, maxi = INT_MIN;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
        maxi = max(maxi, x);
    }
    int ans = INT_MIN;
    for (int i = 0, cur = 0; i < n; ++i) {
        if (v[i] == maxi) {
            cur++;
        } else {
            ans = max(ans, cur);
            cur = 0;
        }
        if (i == n - 1) {
            ans = max(ans, cur);
        }
    }
    cout << ans;
}
