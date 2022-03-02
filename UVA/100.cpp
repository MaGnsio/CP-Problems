/**
 *    author:  MaGnsi0
 *    created: 10.02.2022 20:08:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    function<int(int)> F = [&](int x) {
        if (x == 1) {
            return 1;
        } else if (x & 1) {
            return F(3 * x + 1) + 1;
        } else {
            return F(x / 2) + 1;
        }
    };
    int l, r;
    while (cin >> l >> r) {
        int ans = 0;
        for (int i = min(l, r); i <= max(l, r); ++i) {
            ans = max(ans, F(i));
        }
        cout << l << " " << r << " " << ans << "\n";
    }
}
