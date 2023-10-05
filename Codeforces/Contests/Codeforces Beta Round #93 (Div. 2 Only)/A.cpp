/**
 *    author:  MaGnsi0
 *    created: 15.02.2022 17:54:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<double> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    double ans = 0.0;
    for (int i = 0; i < n - 1; ++i) {
        ans += sqrt((x[i] - x[i + 1]) * (x[i] - x[i + 1]) + (y[i] - y[i + 1]) * (y[i] - y[i + 1]));
    }
    ans *= (k / 50.0);
    cout << fixed << setprecision(9) << ans;
}
