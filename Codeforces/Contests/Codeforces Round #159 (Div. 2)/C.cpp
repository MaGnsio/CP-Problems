/**
 *    author:  MaGnsi0
 *    created: 16.02.2022 06:37:37
**/
#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<double> slope(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        slope[i] = atan2(y, x) * 180.0 / PI;
    }
    sort(slope.begin(), slope.end());
    double ans = slope[n - 1] - slope[0];
    for (int i = 1; i < n; ++i) {
        ans = min(ans, 360.0 - (slope[i] - slope[i - 1]));
    }
    cout << fixed << setprecision(12) << ans;
}
