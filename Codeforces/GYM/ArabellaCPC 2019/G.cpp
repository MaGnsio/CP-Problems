/**
 *    author:  MaGnsi0
 *    created: 23.10.2023 02:14:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    long double ans = 0;
    for (int64_t x = 1; x <= n; ++x) {
        ans += 1.0 * x * (x - 1) / n;
    }
    cout << fixed << setprecision(10) << ans;
}
