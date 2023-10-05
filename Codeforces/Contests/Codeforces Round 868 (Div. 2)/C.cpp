/**
 *    author:  MaGnsi0
 *    created: 04.05.2023 18:32:13
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
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            for (int j = 2; j * j <= a[i]; ++j) {
                while (a[i] % j == 0) {
                    a[i] /= j;
                    mp[j]++;
                }
            }
            if (a[i] > 1) {
                mp[a[i]]++;
            }
        }
        int ans = 0, s = 0;
        for (auto [x, y] : mp) {
            ans += y / 2;
            s += y % 2;
        }
        cout << ans + s / 3 << "\n";
    }
}
