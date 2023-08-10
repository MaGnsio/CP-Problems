#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int64_t> b(n + 1, 0);
        for (int i = 0; i < m; ++i) {
            int l, r;
            cin >> l >> r;
            b[l - 1]++, b[r]--;
        }
        for (int i = 1; i < n; ++i) {
            b[i] += b[i - 1];
        }
        vector<pair<int64_t, int>> c;
        for (int i = 0; i < n; ++i) {
            c.emplace_back(b[i], i);
        }
        sort(a.rbegin(), a.rend());
        sort(c.rbegin(), c.rend());
        int64_t sum = 0;
        vector<int64_t> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[c[i].second] = a[i];
            sum += a[i] * c[i].first;
        }
        cout << sum << "\n";
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
