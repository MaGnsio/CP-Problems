/**
 *    author:  MaGnsi0
 *    created: 13.02.2022 19:36:35
**/
#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

struct point {
    long double x, y;
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, point>> v(n);
    for (int i = 0; i < n; ++i) {
        v[i].first = i + 1;
        cin >> v[i].second.x >> v[i].second.y;
    }
    sort(v.begin(), v.end(), [](pair<int, point> p1, pair<int, point> p2) {
            return isless(atan2(p1.second.y, p1.second.x), atan2(p2.second.y, p2.second.x));
       });
    int a = v[0].first, b = v[n - 1].first;
    long double theta = 2 * PI - (atan2(v[n - 1].second.y, v[n - 1].second.x) - atan2(v[0].second.y, v[0].second.x));
    for (int i = 1; i < n; ++i) {
        long double theta2 = atan2(v[i].second.y, v[i].second.x) - atan2(v[i - 1].second.y, v[i - 1].second.x);
        if (isless(theta2, theta)) {
            a = v[i].first;
            b = v[i - 1].first;
            theta = theta2;
        }
    }
    cout << a << " " << b;
}
