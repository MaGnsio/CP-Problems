/**
 *    author:  MaGnsi0
 *    created: 24.01.2024 18:03:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> a(3), b(3);
    for (int i = 0; i < 3; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 3; ++i) {
        cin >> b[i];
    }
    function<int(int)> F = [&](int x) {
        if (x < 5) { return b[0]; }
        if (x < 10) { return b[1]; }
        return b[2];
    };
    int ans = F(a[0]) + F(a[1]) + F(a[2]);
    ans = min(ans, F(a[0] + a[1]) + F(a[2]));
    ans = min(ans, F(a[0]) + F(a[1] + a[2]));
    ans = min(ans, F(a[0] + a[2]) + F(a[1]));
    ans = min(ans, F(a[0] + a[1] + a[2]));
    cout << ans;
}
