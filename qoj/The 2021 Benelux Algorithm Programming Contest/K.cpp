/**
 *    author:  MaGnsi0
 *    created: 05.10.2023 21:43:55
**/
#include <bits/stdc++.h>

using namespace std;

const long double eps = 1e-6;

long double dist(long double x1, long double y1, long double x2, long double y2) {
    long double dx = x1 - x2;
    long double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    long double L; cin >> L;
    int x = 0, y = 0;
    vector<double> X(1, 0), Y(1, 0);
    while (true) {
        int x_ = x, y_ = y;
        if (x % 2 == 0 && y == 0) { y_ = m; }
        if (x % 2 == 0 && y == m) { x_++; }
        if (x % 2 == 1 && y == 0) { x_++; }
        if (x % 2 == 1 && y == m) { y_ = 0; }
        long double D = dist(x, y, x_, y_) + dist(x_, y_, n, m);
        if (L > D) {
            L -= dist(x, y, x_, y_);
            x = x_, y = y_;
            X.push_back(x);
            Y.push_back(y);
            continue;
        }
        long double low = 0, high = 1;
        for (int _ = 0; _ <= 100; _++) {
            long double mid = (low + high) / 2;
            long double x_mid = x_ * mid + x * (1 - mid);
            long double y_mid = y_ * mid + y * (1 - mid);
            D = dist(x, y, x_mid, y_mid) + dist(x_mid, y_mid, n, m);
            if (L > D) {
                low = mid;
            } else {
                high = mid;
            }
        }
        long double x_mid = x_ * low + x * (1 - low);
        long double y_mid = y_ * low + y * (1 - low);
        if (low > 0 && low < 1) {
            X.push_back(x_mid);
            Y.push_back(y_mid);
        }
        X.push_back(n);
        Y.push_back(m);
        break;
    }
    int k = (int)X.size();
    cout << k << "\n";
    cout << fixed << setprecision(6);
    for (int i = 0; i < k; ++i) {
        cout << X[i] << " " << Y[i] << "\n";
    }
}
