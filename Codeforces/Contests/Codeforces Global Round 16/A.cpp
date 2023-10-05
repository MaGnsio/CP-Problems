/**
 *    author:  MaGnsi0
 *    created: 12/09/2021 16:29:22
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, s;
        cin >> n >> s;
        int b = (n + 1) / 2 - 1;
        int res = s / (n - b);
        cout << res << "\n";
    }
}
