/**
 *    author:  MaGnsi0
 *    created: 25.09.2022 16:34:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, c;
        cin >> n >> c;
        vector<int> a(101, 0);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[x]++;
        }
        int ans = 0;
        for (int i = 0; i < 101; ++i) {
            ans += min(c, a[i]);
        }
        cout << ans << "\n";
    }
}
