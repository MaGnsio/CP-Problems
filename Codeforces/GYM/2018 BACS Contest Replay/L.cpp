/**
 *    author:  MaGnsi0
 *    created: 20.10.2023 17:02:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        int m; cin >> m;
        vector<int> a(n), b(n), c;
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
            c.push_back(a[i]);
            c.push_back(b[i]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        c.resize(unique(c.begin(), c.end()) - c.begin());
        function<bool(int)> F = [&](int x) {
            int have = 0, i = 0, j = 0;
            for (int enter : c) {
                while (i < n && a[i] <= enter + x) {
                    have++, i++;
                }
                while (j < n && b[j] < enter) {
                    have--, j++;
                }
                if (have >= m) { return true; }
            }
            return false;
        };
        int low = 0, high = 1e9, ans = 1e9;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (F(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << "Case " << t << ": " << ans << "\n";
    }
}
