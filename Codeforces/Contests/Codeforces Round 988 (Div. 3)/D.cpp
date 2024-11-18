/**
 *    author:  MaGnsi0
 *    created: 18.11.2024 18:58:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int k; cin >> k;
        vector<int> a(n), b(n), c(m), d(m);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> c[i] >> d[i];
        }
        int ans = 0, power = 0;
        multiset<int> available;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < m && c[j] < a[i]) {
                available.insert(d[j++]);
            }
            while (!available.empty() && power < b[i] - a[i] + 1) {
                power += *available.rbegin();
                available.erase(available.find(*available.rbegin()));
                ans++;
            }
            if (power < b[i] - a[i] + 1) {
                ans = -1;
                break;
            }
        }
        cout << ans << "\n";
    }
}
