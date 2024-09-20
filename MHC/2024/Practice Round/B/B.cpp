/**
 *    author:  MaGnsi0
 *    created: 21.09.2024 01:40:47
**/
#include <bits/stdc++.h>

using namespace std;

const double delta = 1e-6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        int P; cin >> P;
        long double p = 1.0 * P / 100;
        long double x = pow(p, 1.0 * (n - 1) / n);
        long double X = 100 * x - 1.0 * P;
        cout << fixed << setprecision(15);
        cout << "Case #" << t << ": " << X << "\n";
    }
}
