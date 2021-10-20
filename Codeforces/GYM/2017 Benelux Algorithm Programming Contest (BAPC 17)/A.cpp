/**
 *    author:  MaGnsi0
 *    created: 03/09/2021 19:37:39
**/
#include <bits/stdc++.h>
using namespace std;

double solve(double m, double n, double r, double x1, double y1, double x2, double y2) {
    double d = r / n;
    double p = acos(-1) * d * min(y1, y2);
    double res = abs(y1 - y2) * d + (p / m) * abs(x1 - x2);
    return res;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    double m, n, r;
    cin >> m >> n >> r;
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double res = 1e9;
    for (int i = 0; i <= (int)m; ++i) {
        for (int j = 0; j <= (int)n; ++j) {
            res = min(res, solve(m, n, r, (double)i, (double)j, x1, y1) + solve(m, n, r, (double)i, (double)j, x2, y2)); 
        }
    }
    cout << fixed << setprecision(14) << res;
}
