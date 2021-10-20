/**
 *    author:  MaGnsi0
 *    created: 13/07/2021 21:52:50
**/
#include <bits/stdc++.h>
using namespace std;

long long f(long long y) {
    long long res = (y / 4) + (y / 400) - (y / 100);
    return res;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long a, b;
    cin >> a >> b;
    long long mod = 104206969, x = 180758, u = b - a + 1, v = (a ? f(b) - f(a - 1) : f(b) + 1);
    long long ans = (((u % mod) * x) % mod + ((v % mod) * 229) % mod) % mod;
    cout << ans % mod;
}
