/**
 *    author:  MaGnsi0
 *    created: 21.09.2023 11:18:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int64_t W, L, X, Y;
    cin >> W >> L >> X >> Y;
    function<int64_t(int, int)> D = [&](int x, int y) {
        return (X - x) * (X - x) + (Y - y) * (Y - y);
    };
    vector<int64_t> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[i] = D(x, y);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        b[i] = D(x, y);
    }
    sort(b.begin(), b.end());
    if (a[0] < b[0]) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += a[i] < b[0];
        }
        cout << "A " << ans;
    } else {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += b[i] < a[0];
        }
        cout << "R " << ans;
    }
}
