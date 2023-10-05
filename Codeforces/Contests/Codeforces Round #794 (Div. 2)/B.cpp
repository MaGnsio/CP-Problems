/**
 *    author:  MaGnsi0
 *    created: 25.05.2022 19:34:25
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
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1]) {
                ans++;
                i++;
            }
        }
        cout << ans << "\n";
    }
}
