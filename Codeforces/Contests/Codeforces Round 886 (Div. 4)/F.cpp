/**
 *    author:  MaGnsi0
 *    created: 21.07.2023 17:59:41
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
            mp[a[i]]++;
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int val = 0;
            for (int j = 1; j * j <= i; ++j) {
                if (i % j == 0) {
                    val += mp[j];
                    if (i != j * j) {
                        val += mp[i / j];
                    }
                }
            }
            ans = max(ans, val);
        }
        cout << ans << "\n";
    }
}
