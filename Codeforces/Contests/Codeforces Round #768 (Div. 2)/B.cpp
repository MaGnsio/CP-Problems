/**
 *    author:  MaGnsi0
 *    created: 05.02.2022 20:52:35
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int res = 0, x = 0;
        reverse(a.begin(), a.end());
        while (x < n - 1) {
            if (a[x + 1] == a[0]) {
                x++;
                continue;
            }
            res++;
            x = 2 * (x + 1) - 1;
        }
        cout << res << "\n";
    }
}
