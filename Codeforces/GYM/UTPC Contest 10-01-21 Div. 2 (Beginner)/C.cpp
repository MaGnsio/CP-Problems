/**
 *    author:  MaGnsi0
 *    created: 22.12.2021 19:32:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int res = 0;
    for (int i = 6; i <= n; ++i) {
        int x = i, cnt = 0;
        for (int j = 2; j * j <= x; ++j) {
            if (x % j == 0) {
                cnt++;
                while (x % j == 0) {
                    x /= j;
                }
            }
        }
        if (x > 1) {
            cnt++;
        }
        res += (cnt == 2);
    }
    cout << res;
}
