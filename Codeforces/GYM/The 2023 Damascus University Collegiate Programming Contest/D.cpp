/**
 *    author:  MaGnsi0
 *    created: 14.07.2023 15:09:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        set<int> banned;
        for (int i = 0; i < n; ++i) {
            for (int j = 2; j * j <= a[i]; ++j) {
                if (a[i] % j == 0) { banned.insert(j); }
                while (a[i] % j == 0) { a[i] /= j; }
            }
            if (a[i] > 1) { banned.insert(a[i]); }
        }
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            int x = i;
            bool coprime = true;
            for (int j = 2; j * j <= x; ++j) {
                if (x % j == 0 && banned.count(j)) { coprime = false; }
                while (x % j == 0) { x /= j; }
            }
            if (x > 1 && banned.count(x)) { coprime = false; }
            ans += coprime;
        }
        cout << ans << "\n";
    }
}
