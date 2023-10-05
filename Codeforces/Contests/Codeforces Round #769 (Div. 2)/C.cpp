/**
 *    author:  MaGnsi0
 *    created: 07.02.2022 20:50:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        int res = b - a;
        for (int i = a; i < b; ++i) {
            int na = i;
            int nb = (na | b);
            int msb = -1;
            for (int j = 20; j >= 0; --j) {
                if (((na >> j) & 1) && !((b >> j) & 1)) {
                    msb = j;
                    break;
                }
            }
            for (int j = msb; j >= 0; --j) {
                if (!((na >> j) & 1) && ((nb >> j) & 1)) {
                    nb ^= (1 << j);
                }
            }
            res = min(res, (na - a) + (nb - b) + 1);
        }
        cout << res << "\n";
    }
}
