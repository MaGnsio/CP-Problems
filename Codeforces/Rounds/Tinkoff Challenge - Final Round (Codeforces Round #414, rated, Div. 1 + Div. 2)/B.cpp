/**
 *    author:  MaGnsi0
 *    created: 15.02.2022 18:06:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, h;
    cin >> n >> h;
    double area = h / 2.0, unit = area / n;
    for (int i = 1; i < n; ++i) {
        double sarea = i * unit;
        double ans = h * sqrt(sarea / area);
        cout << fixed << setprecision(12) << ans << " ";
    }
}
