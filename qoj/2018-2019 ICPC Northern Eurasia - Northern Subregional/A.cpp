/**
 *    author:  MaGnsi0
 *    created: 28.09.2023 23:37:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, p;
    cin >> t >> p;
    int x = min(100 - p, 80);
    int y = max(20 - p, 0);
    double tb = 1.0 * t / (x + 2 * y);
    double ans = tb * max(p - 20, 0) + 2 * tb * min(20, p);
    cout << fixed << setprecision(7) << ans;
}
