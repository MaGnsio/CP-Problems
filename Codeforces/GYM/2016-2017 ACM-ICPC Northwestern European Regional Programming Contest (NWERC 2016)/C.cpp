/**
 *    author:  MaGnsi0
 *    created: 01.03.2022 22:14:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, y, n;
    cin >> x >> y >> n;
    if (n) {
        vector<pair<pair<int, int>, double>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first.first >> a[i].first.second >> a[i].second;
        }
        sort(a.begin(), a.end());
        double Y = a[0].first.first;
        for (int i = 0; i < n; ++i) {
            Y += (a[i].first.second - a[i].first.first) * a[i].second;
            if (i) {
                Y += (a[i].first.first - a[i - 1].first.second);
            }
        }
        Y += (y - a[n - 1].first.second);
        double ans = 1.0 * x / Y;
        cout << fixed << setprecision(12) << ans;
    } else {
        double ans = 1.0 * x / y;
        cout << fixed << setprecision(12) << ans;
    }
}
