/**
 *    author:  MaGnsi0
 *    created: 07.04.2023 23:37:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        if ((x + y) & 1) {
            cout << -1 << " " << -1 << "\n";
            continue;
        }
        int add = (x + y) / 2;
        int ans_x = min(add, x);
        add -= ans_x;
        int ans_y = add;
        cout << ans_x << " " << ans_y << "\n";
    }
}
