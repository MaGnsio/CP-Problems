/**
 *    author:  MaGnsi0
 *    created: 15.10.2021 21:47:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long r, g, b;
    cin >> r >> g >> b;
    long long res = min((r + g + b) / 3, r + g + b - max({r, g, b}));
    cout << res;
}
