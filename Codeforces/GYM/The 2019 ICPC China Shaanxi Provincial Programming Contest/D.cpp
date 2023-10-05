/**
 *    author:  MaGnsi0
 *    created: 20.09.2023 19:18:43
**/
#include <bits/stdc++.h>

using namespace std;

double D(int x1, int y1, int x2, int y2, int v) {
    return 1.0 * (abs(x1 - x2) + abs(y1 - y2)) / v;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a; cin >> a;
        int b; cin >> b;
        vector<int> X(3), Y(3);
        for (int i = 0; i < 3; ++i) {
            cin >> X[i] >> Y[i];
        }
        double ans = D(X[0], Y[0], X[2], Y[2], a);
        int Xl = min(X[0], X[1]), Xr = max(X[0], X[1]);
        int Yl = min(Y[0], Y[1]), Yr = max(Y[0], Y[1]);
        int Xm = max(Xl, min(Xr, X[2]));
        int Ym = max(Yl, min(Yr, Y[2]));
        double W1 = D(X[0], Y[0], Xm, Ym, a);
        double W2 = D(X[1], Y[1], Xm, Ym, b);
        if (W1 > W2) {
            ans = min(ans, D(X[1], Y[1], X[2], Y[2], b));
        } else {
            double t1 = D(X[0], Y[0], X[1], Y[1], a + b);
            double t2 = 1.0 * (abs(X[0] - X[2]) + abs(Y[0] - Y[2]) - a * t1) / b;
            ans = min(ans, t1 + t2);
        }
        cout << fixed << setprecision(8) << ans << "\n";
    }
}
