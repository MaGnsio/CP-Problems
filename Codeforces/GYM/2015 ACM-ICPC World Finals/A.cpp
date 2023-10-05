/**
 *    author:  MaGnsi0
 *    created: 09.09.2023 11:02:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int p; cin >> p;
    int a; cin >> a;
    int b; cin >> b;
    int c; cin >> c;
    int d; cin >> d;
    int n; cin >> n;
    function<double(int)> price = [&](int k) {
        return p * (sin(a * k + b) + cos(c * k + d) + 2);
    };
    double ans = 0.0, maxp = 0.0;
    for (int k = 1; k <= n; ++k) {
        ans = max(ans, maxp - price(k));
        maxp = max(maxp, price(k));
    }
    cout << fixed << setprecision(8) << ans;
}
