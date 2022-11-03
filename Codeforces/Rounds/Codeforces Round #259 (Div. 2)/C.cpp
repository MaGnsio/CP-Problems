/**
 *    author:  MaGnsi0
 *    created: 20.06.2022 16:39:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m, n;
    cin >> m >> n;
    long double ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans += 1.0 * i * (pow(1.0 * i / m, n) - pow(1.0 * (i - 1) / m, n));
    }
    cout << fixed << setprecision(8) << ans;
}
