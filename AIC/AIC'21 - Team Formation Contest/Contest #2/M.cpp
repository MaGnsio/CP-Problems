/**
 *    author:  MaGnsi0
 *    created: 17/07/2021 13:36:40
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    int x = n / a, y = n / b, z = n / (a * b / gcd(a, b));
    x -= z, y -= z;
    int res = (x * p) + (y * q) + (max(p, q) * z);
    cout << res;
}
