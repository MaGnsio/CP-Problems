/**
 *    author:  MaGnsi0
 *    created: 11.03.2022 19:13:48
**/
#include <bits/stdc++.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("plus.in", "r", stdin);
    long long x, y, l, r;
    cin >> x >> y >> l >> r;
    auto F = [](long long n, long long x) {
        return 1LL * (n / x);
    };
    cout << (F(r, x) - F(l - 1, x)) + (F(r, y) - F(l - 1, y)) - (F(r, 1LL * x * y / __gcd(x, y)) - F(l - 1, 1LL * x * y / __gcd(x, y)));
}
