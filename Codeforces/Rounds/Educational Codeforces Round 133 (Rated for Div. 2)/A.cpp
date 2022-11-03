/**
 *    author:  MaGnsi0
 *    created: 04.08.2022 16:34:21
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
        int ans = n / 3 + 1 * (n % 3 == 1) + 1 * (n % 3 == 2) + 1 * (n == 1);
        cout << ans << "\n";
    }
}
