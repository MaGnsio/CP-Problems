/**
 *    author:  MaGnsi0
 *    created: 17.12.2024 21:19:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        map<int, int> mp1, mp2;
        for (int i = n - 1; i >= 0; --i) {
            mp1[a[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            mp2[a[i]] = i;
        }
        vector<int> b(n);
        for (auto [_, j] : mp2) { b[j]++; }
        for (int i = n - 2; i >= 0; --i) {
            b[i] += b[i + 1];
        }
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            if (mp1[a[i]] != i) { continue; }
            ans += b[i];
        }
        cout << ans << "\n";
    }
}
