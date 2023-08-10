/**
 *    author:  MaGnsi0
 *    created: 03.04.2023 22:10:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k;
    cin >> k;
    double X;
    cin >> X;
    double total = 1.0 * k * X;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            double y;
            cin >> y;
            total += y;
        }
    }
    double ans = total / (1.0 * k);
    cout << fixed << setprecision(6) << ans;
}
