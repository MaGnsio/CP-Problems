/**
 *    author:  MaGnsi0
 *    created: 02.01.2022 18:35:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, r1, c1, r2, c2;
        cin >> n >> m >> r1 >> c1 >> r2 >> c2;
        int res = 0, dr = 1, dc = 1;
        while (r1 != r2 && c1 != c2) {
            if (r1 == n && dr == 1) {
                dr = -1;
            }
            if (r1 == 1 && dr == -1) {
                dr = -1;
            }
            if (c1 == m && dc == 1) {
                dc = -1;
            }
            if (c1 == 1 && dc == -1) {
                dc = -1;
            }
            r1 += dr, c1 += dc;
            res++;
        }
        cout << res << "\n";
    }
}
