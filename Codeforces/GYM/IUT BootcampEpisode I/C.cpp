/**
 *    author:  MaGnsi0
 *    created: 12/07/2021 04:13:09
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, cnt = 0;
        cin >> n;
        // a^2 + b^2 = c^2, c = a^2 - b -> c^2 - c = b^2 - b -> c*(c - 1) = b*(b + 1) -> c = b + 1
        // a^2 = 2*b + 1 (a & b >= 1 for every odd a > 1)
        for (int i = 3; (i * i + 1) / 2 <= n; i += 2) {
            cnt++;
        }
        cout << cnt << "\n";
    }
}
