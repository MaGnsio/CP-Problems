/**
 *    author:  MaGnsi0
 *    created: 16.10.2023 16:40:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int x; cin >> x;
    int y; cin >> y;
    if (abs(x) + abs(y) > n) {
        cout << -1;
        return 0;
    }
    vector<vector<int>> a(4, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') { a[0][i]++; }
        if (s[i] == 'L') { a[1][i]++; }
        if (s[i] == 'U') { a[2][i]++; }
        if (s[i] == 'D') { a[3][i]++; }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            a[j][i] += a[j][i - 1];
        }
    }
    function<bool(int)> F = [&](int M) {
        if (M == 0) {
            return (a[0][n - 1] - a[1][n - 1] == x) && (a[2][n - 1] - a[3][n - 1] == y);
        }
        for (int i = 0; i + M - 1 < n; ++i) {
            int X = (i ? a[0][i - 1] - a[1][i - 1] : 0);
            X += a[0][n - 1] - a[0][i + M - 1];
            X -= a[1][n - 1] - a[1][i + M - 1];
            int Y = (i ? a[2][i - 1] - a[3][i - 1] : 0);
            Y += a[2][n - 1] - a[2][i + M - 1];
            Y -= a[3][n - 1] - a[3][i + M - 1];
            int rem = M - abs(x - X) - abs(y - Y);
            if (rem >= 0 && rem % 2 == 0) { return true; }
        }
        return false;
    };
    int low = 0, high = n, ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (F(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans;
}
