#include <bits/stdc++.h>
using namespace std;

const double PI= acos(-1);

int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int n, s;
    cin >> n >> s;
    int x[n], y[n], z[n], r[n];
    double total = 1e15;
    for(int i = 0; i < n; ++i){
        cin >> r[i] >> x[i] >> y[i] >> z[i];
        total -= (4.0 / 3) * PI * r[i] * r[i] * r[i];
    }
    function<double(double)> calc= [&](double h) {
        double area= 1e10 * h;
        for (int i = 0; i < n; ++i) {
            if (z[i] + r[i] <= h) {
                area -= (4.0 / 3) * PI * r[i] * r[i] * r[i];
            } else if (h <= z[i] + r[i] && h >= z[i] - r[i]) {
                double hh= h - (z[i] - r[i]);
                double rr = r[i];
                area -= (1.0 / 3) * PI * hh * hh * (3 * rr - hh);
            }
        }
        return area;
    };
    double each = total / s, prev = 0;
    for (int i = 1; i <= s; ++i) {
        double need = each * i;
        double L = 0, R = 1e5, res = 1e5;
        for (int k = 0; k < 60; ++k) {
            double md = (L + R) * 0.5;
            double area = calc(md);
            if(area < need) {
                L = md;
            } else {
                R = md, res = md;
            }
        }
        cout << fixed << setprecision(12) << (res - prev) / (1000.0) << "\n";
        prev = res;
    }
}
