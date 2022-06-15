/**
 *    author:  MaGnsi0
 *    created: 05.03.2022 13:54:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    double ans;
    if (x <= a) {
        ans = 1;
    } else if (x <= b) {
        ans = 1.0 * c / (b - a);
    } else {
        ans = 0;
    }
    cout << fixed << setprecision(12) << ans;
}
