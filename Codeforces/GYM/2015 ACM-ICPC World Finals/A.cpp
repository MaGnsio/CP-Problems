/**
 *    author:  MaGnsi0
 *    created: 22.09.2022 20:40:00
**/
#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long double p, a, b, c, d;
    int n;
    cin >> p >> a >> b >> c >> d >> n;
    function<long double(long double)> F = [&](long double k) {
        long double ans = p * (sin(a * k + b) + cos(c * k + d) + 2.0);
        return ans;
    };
    vector<long double> price(n);
    for (int i = 1; i <= n; ++i) {
        price[i - 1] = F(i);
    }
    long double ans = 0.0, cur_max = price[0];
    for (int i = 1; i < n; ++i) {
        if (isless(cur_max, price[i])) {
            cur_max = price[i];
        } else {
            ans = max(ans, cur_max - price[i]);
        }
    }
    cout << fixed << setprecision(9) << ans;
}
