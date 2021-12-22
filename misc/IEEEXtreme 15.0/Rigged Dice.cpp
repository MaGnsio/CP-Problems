/**
 *    author:  MaGnsi0
 *    created: 23.10.2021 06:21:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int res[2] = {};
        int a = 0, b = 0;
        int f = 0, s = 1;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            a += x, b += y;
            res[f] += (x == 6);
            res[s] += (y == 6);
            if (a != b) {
                swap(f, s);
            }
        }
        cout << (res[0] > res[1] ? 1 : 2) << "\n";
    }
}
