/**
 *    author:  MaGnsi0
 *    created: 22/07/2021 16:37:11
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int res = (n / 10) + ((n + 1) % 10 == 0);
        cout << res << "\n";
    }
}
