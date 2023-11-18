/**
 *    author:  MaGnsi0
 *    created: 07.10.2023 11:07:28
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
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        vector<set<int64_t>> s(2);
        s[1].insert(0);
        s[0].insert(a[0]);
        int64_t ans = a[0];
        for (int i = 1; i < n; ++i) {
            ans = max(ans, a[i] - *s[!(i % 2)].begin());
            ans = max(ans, a[i] - *s[!(i % 2)].rbegin());
            s[i % 2].insert(a[i]);
        }
        cout << ans << "\n";
    }
}
