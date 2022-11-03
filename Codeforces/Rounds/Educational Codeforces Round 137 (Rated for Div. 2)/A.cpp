/**
 *    author:  MaGnsi0
 *    created: 17.10.2022 16:35:59
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
        vector<int> _(n);
        for (int i = 0; i < n; ++i) {
            cin >> _[i];
        }
        n = 10 - n;
        int ans = 3 * n * (n - 1);
        cout << ans << "\n";
    }
}
