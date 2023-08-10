/**
 *    author:  MaGnsi0
 *    created: 04.07.2023 17:53:21
**/
#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

double sphericalDistance(double f1, double t1, double f2, double t2, double radius) {
    double dx = cos(f2) * cos(t2) - cos(f1) * cos(t1);
    double dy = cos(f2) * sin(t2) - cos(f1) * sin(t1);
    double dz = sin(f2) - sin(f1);
    double d = sqrt(dx * dx + dy * dy + dz * dz);
    return radius * 2 * asin(d / 2);
}

class Travel {
    public:
        int shortest(vector<string> a, int r) {
            int n = (int)a.size();
            vector<double> x(n), y(n);
            for (int i = 0; i < n; ++i) {
                stringstream sin(a[i]);
                sin >> x[i] >> y[i];
                x[i] *= PI / 180.0;
                y[i] *= PI / 180.0;
            }
            vector<vector<double>> dp((1 << n), vector<double>(n, 1e9));
            vector<vector<bool>> v((1 << n), vector<bool>(n, false));
            function<double(int, int)> solve = [&](int mask, int j) {
                if (mask == (1 << n) - 1) {
                    return sphericalDistance(x[0], y[0], x[j], y[j], r);
                }
                if (v[mask][j]) {
                    return dp[mask][j];
                }
                v[mask][j] = true;
                for (int i = 0; i < n; ++i) {
                    if ((mask >> i) & 1) { continue; }
                    dp[mask][j] = min(dp[mask][j], sphericalDistance(x[i], y[i], x[j], y[j], r) + solve(mask | (1 << i), i));
                }
                return dp[mask][j];
            };
            return round(solve(1, 0));
        }
};
