/**
 *    author:  MaGnsi0
 *    created: 15.02.2022 05:30:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    long long ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        long long r1 = (x[i] - x1) * (x[i] - x1) + (y[i] - y1) * (y[i] - y1), r2 = 0;
        for (int j = 0; j < n; ++j) {
            if ((x[j] - x1) * (x[j] - x1) + (y[j] - y1) * (y[j] - y1) <= r1) {
                continue;
            }
            r2 = max(r2, (x[j] - x2) * (x[j] - x2) + (y[j] - y2) * (y[j] - y2));
        }
        ans = min(ans, r1 + r2);
    }
    long long r1 = 0, r2 = 0;
    for (int j = 0; j < n; ++j) {
        if ((x[j] - x1) * (x[j] - x1) + (y[j] - y1) * (y[j] - y1) <= r1) {
            continue;
        }
        r2 = max(r2, (x[j] - x2) * (x[j] - x2) + (y[j] - y2) * (y[j] - y2));
    }
    ans = min(ans, r1 + r2);
    cout << ans;
}
