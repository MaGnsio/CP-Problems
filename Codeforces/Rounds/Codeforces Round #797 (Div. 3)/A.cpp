/**
 *    author:  MaGnsi0
 *    created: 07.06.2022 16:34:04
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
        int x = n / 3, y = n % 3;
        int res1 = x, res2 = x, res3 = x;
        if (y == 2) {
            res1 += 2;
            res2++;
            res3--;
        } else if (y == 1) {
            res1 += 2;
            res3--;
        } else {
            res1++;
            res3--;
        }
        cout << res2 << " " << res1 << " " << res3 << "\n";
    }
}
