/**
 *    author:  MaGnsi0
 *    created: 05.02.2023 09:03:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long double l, r;
    cin >> l >> r;
    if (r - l > 100000000) {
        cout << 2;
    } else {
        long double ans = 1, p = 1;
        for (int i = 1; i <= r - l; ++i) {
            p *= 0.5;
            ans += p; 
        }
        cout << fixed << setprecision(10) << ans;
    }
}
