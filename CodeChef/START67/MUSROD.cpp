/**
 *    author:  MaGnsi0
 *    created: 30.11.2022 16:51:33
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
        vector<int64_t> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        vector<pair<int64_t, int64_t>> c(n);
        for (int i = 0; i < n; ++i) {
            c[i] = make_pair(b[i], a[i]);
        }
        sort(c.begin(), c.end(), [&](pair<int64_t, int64_t> x, pair<int64_t, int64_t> y) {
                return (x.first * y.second < y.first * x.second);
            });
        //a[j].first * a[k].second
        //a[j].second * a[l].first
        int64_t ans = 0, x = 0;
        for (int i = 0; i < n; ++i) {
            ans += x * c[i].first;
            x += c[i].second;
        }
        cout << ans << "\n";
    }
}
