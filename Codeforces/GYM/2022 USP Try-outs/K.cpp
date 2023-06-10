/**
 *    author:  MaGnsi0
 *    created: 02.06.2023 22:34:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, b;
    cin >> n >> b;
    vector<int64_t> a;
    for (int i = 0; i < n; ++i) {
        int64_t x, y, t, v;
        cin >> x >> y >> t >> v;
        if (y - x <= t) { continue; }
        if (y <= b * t) {
            a.push_back(v);
        }
    }
    sort(a.rbegin(), a.rend());
    int64_t m = (int)a.size(), gain = 0, ans = 0;
    for (int i = 0; i < m; ++i) {
        if (a[i] * (i + 1) >= gain) {
            gain = a[i] * (i + 1);
            ans = a[i];
        }
    }
    cout << ans;
}
