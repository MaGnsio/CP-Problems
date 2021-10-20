/**
 *    author:  MaGnsi0
 *    created: 13/07/2021 23:07:01
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int h, w, x, y, ans = INT_MAX;
    cin >> h >> w >> x >> y;
    vector<int> a = {0, h + 1, 0, h + 1};
    vector<int> b = {0, w + 1, w + 1, 0};
    for (int i = 0; i < 4; ++i) {
        ans = min(ans, abs(x - a[i]) * abs(y - b[i]));
    }
    if (ans >= h * w - ans) {
        cout << "I don't wanna do this anymore!";
    } else {
        cout << ans;
    }
}
