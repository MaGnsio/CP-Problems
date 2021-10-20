/**
 *    author:  MaGnsi0
 *    created: 17/07/2021 13:36:30
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, sum = 0, mod = 1e9 + 7;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum = (sum + x) % mod;
    }
    for (int i = 0; i < n - 1; ++i) {
        sum = (sum * 2) % mod;
    }
    cout << sum % mod;
}
