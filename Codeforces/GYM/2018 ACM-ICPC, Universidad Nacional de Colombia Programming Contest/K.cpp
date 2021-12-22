/**
 *    author:  MaGnsi0
 *    created: 09.11.2021 13:06:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<double, double>> a;
    for (int i = 0; i < n; ++i) {
        int x;
        double y;
        cin >> x >> y;
        if (x == 0) {
            continue;
        }
        a.push_back({x, y});
    }
    sort(a.begin(), a.end(), [](pair<double, double> x, pair<double, double> y) {
            return isless(x.first * x.second, y.first * y.second);
       });
    double res = 0.0, cur = 0.0;
    for (int i = 0; i < (int)a.size(); ++i) {
        cur += (a[i].first * a[i].second);
        res += cur;
    }
    res /= n;
    cout << fixed << setprecision(7) << res;
}
