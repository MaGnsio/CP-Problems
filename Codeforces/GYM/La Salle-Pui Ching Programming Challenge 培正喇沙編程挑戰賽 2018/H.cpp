/**
 *    author:  MaGnsi0
 *    created: 11/08/2021 11:35:43
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        p.emplace_back(x, i);
    }
    sort(p.begin(), p.end());
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        int d = y - x;
        int l = 0, r = n - 1, idx = 0;
        if (!d) {
            cout << 0 << "\n";
            continue;
        }
        while (l <= r) {
            int mid = (l + r) / 2;
            if (p[mid].first >= y) {
                r = mid - 1;
                continue;
            }
            if (p[mid].first <= d) {
                l = mid + 1;
                idx = p[mid].second + 1;
            } else {
                r = mid - 1;
            }
        }
        l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (p[mid].first >= y) {
                r = mid - 1;
                continue;
            }
            if (p[mid].first >= d) {
                r = mid - 1;
                if (abs(p[idx - 1].first - d) > abs(p[mid].first - d)) {
                    idx = p[mid].second + 1;
                }
            } else {
                l = mid + 1;
            }
        }
        cout << (d <= abs(d - p[idx - 1].first) ? 0 : idx) << "\n";
    }
}
