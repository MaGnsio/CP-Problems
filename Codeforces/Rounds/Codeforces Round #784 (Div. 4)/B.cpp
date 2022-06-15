/**
 *    author:  MaGnsi0
 *    created: 22.04.2022 09:57:29
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
        int ans = -1;
        for (int i = 0; i + 2 < n; ++i) {
            if (a[i] == a[i + 1] && a[i + 1] == a[i + 2]) {
                ans = a[i];
                break;
            }
        }
        cout << ans << "\n";
    }
}
