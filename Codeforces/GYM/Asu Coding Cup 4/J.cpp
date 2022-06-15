/**
 *    author:  MaGnsi0
 *    created: 02.06.2022 16:27:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x, a;
    cin >> n >> x >> a;
    int m = a / x;
    int ans = (n + m - 1) / m;
    cout << ans;
}
