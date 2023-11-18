/**
 *    author:  MaGnsi0
 *    created: 04.10.2023 16:16:22
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
        unordered_map<int, int> mp;
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j - 1; ++i) {
                mp[a[i] + a[j]]--;
            }
            for (int k = j + 1; k < n; ++k) {
                mp[a[j - 1] + a[k]]++;
            }
            ans += mp[2 * a[j]];
        }
        cout << ans << "\n";
    }
}
