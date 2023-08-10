/**
 *    author:  MaGnsi0
 *    created: 18.06.2023 11:05:54
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
        int ans = 0, x = count(a.begin(), a.end(), 1), y = n - x;
        while (!(x >= y && y % 2 == 0)) {
            ans++, x++, y--;
        }
        cout << ans << "\n";
    }
}
