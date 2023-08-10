/**
 *    author:  MaGnsi0
 *    created: 30.03.2023 22:03:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int min_x = 1e6, max_x = -1e6;
    int min_y = 1e6, max_y = -1e6;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        min_x = min(min_x, x);
        max_x = max(max_x, x);
        min_y = min(min_y, y);
        max_y = max(max_y, y);
    }
    cout << 2 * (max_x - min_x + max_y - min_y);
}
