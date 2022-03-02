/**
 *    author:  MaGnsi0
 *    created: 15.02.2022 19:01:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    while ((cin >> n) && n) {
        vector<long long> x(n), y(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            long long dx = x[i] - x[n / 2];
            long long dy = y[i] - y[n / 2];
            if (!dx || !dy) {
                continue;
            }
            a += (dx * dy > 0);
            b += (dx * dy < 0);
        }
        cout << a << " " << b << "\n";
    }
}
