/**
 *    author:  MaGnsi0
 *    created: 13.01.2023 23:48:29
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
        sort(a.begin(), a.end());
        int x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            x += a[i] == 0;
            y += i && a[i - 1] == a[i];
        }
        int ans = (x ? n - x : (y ? n : n + 1));
        cout << ans << "\n";
    }
}
