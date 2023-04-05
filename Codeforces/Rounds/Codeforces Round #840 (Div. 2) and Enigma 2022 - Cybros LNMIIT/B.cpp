/**
 *    author:  MaGnsi0
 *    created: 20.12.2022 20:46:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
        }
        sort(a.begin(), a.end());
        vector<int> minP(n);
        minP[n - 1] = a[n - 1].second;
        for (int i = n - 2; i >= 0; --i) {
            minP[i] = min(a[i].second, minP[i + 1]);
        }
        bool ok = false;
        int64_t reduced_by = 0;
        while (k > 0) {
            reduced_by += 1LL * k;
            int l = 0, r = n - 1, j = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (a[m].first > reduced_by) {
                    j = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            if (j == -1) { ok = true; break; }
            k -= minP[j];
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
