/**
 *    author:  MaGnsi0
 *    created: 22.10.2021 20:41:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, y;
    cin >> x >> y;
    cout << (7 - max(x, y)) / gcd(6, 7 - max(x, y)) << "/" << 6 / gcd(6, 7 - max(x, y));
}
