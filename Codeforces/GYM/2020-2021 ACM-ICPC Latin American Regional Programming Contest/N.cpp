/**
 *    author:  MaGnsi0
 *    created: 05/10/2021 23:13:55
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, x, y, res = 0;
    char trivial;
    cin >> n;
    cin >> trivial >> x >> trivial >> y;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> trivial >> a >> trivial >> b;
        x += a, y += b;
        int r = y / 100;
        x += r;
        y -= (r * 100);
        res += (y != 0);
    }
    cout << res;
}
