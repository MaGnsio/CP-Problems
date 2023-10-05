/**
 *    author:  MaGnsi0
 *    created: 13.09.2023 16:38:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for  (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }
    int64_t ans = 0, odds = 0, evens = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] & 1) {
            ans += evens;
            odds++;
        } else {
            ans += odds;
            evens++;
        }
    }
    cout << ans;
}
