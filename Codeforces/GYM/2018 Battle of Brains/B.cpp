/**
 *    author:  MaGnsi0
 *    created: 17/08/2021 18:51:08
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        double m, d;
        cin >> m >> d;
        double v = m / d;
        double r = pow((3.0 * v) / (4.0 * acos(-1)), 1.0 / 3.0);
        double a = 4.0 * acos(-1) * r * r;
        cout << "Case " << t << ": ";
        cout << fixed << setprecision(4) << a << "\n";
    }
}
