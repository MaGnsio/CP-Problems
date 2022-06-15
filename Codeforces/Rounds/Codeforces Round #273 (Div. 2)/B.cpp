/**
 *    author:  MaGnsi0
 *    created: 10.03.2022 11:53:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, m;
    cin >> n >> m;
    long long x = n - m;
    long long maxf = x * (x + 1) / 2;
    long long y = n / m, r = n % m;
    long long minf = (m - r) * y * (y - 1) / 2 + r * y * (y + 1) / 2;
    cout << minf << " " << maxf;
}
