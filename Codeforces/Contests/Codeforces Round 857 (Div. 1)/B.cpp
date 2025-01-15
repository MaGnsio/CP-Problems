/**
 *    author:  MaGnsi0
 *    created: 16.01.2025 00:11:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<array<int, 2>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i][0] >> a[i][1];
        }
        int ans = INT_MAX;
        for (int _ = 0; _ < 2; ++_) {
            sort(a.begin(), a.end());
            vector<int> maxs(n);
            for (int i = n - 1; i >= 0; --i) {
                maxs[i] = a[i][1];
                if (i + 1 < n) {
                    maxs[i] = max(maxs[i], maxs[i + 1]);
                }
            }
            set<int> optional;
            function<int(int)> nearst = [&](int x) {
                if (optional.empty()) { return -1; }
                auto it = optional.lower_bound(x);
                if (it == optional.end()) { return -1; }
                return *it;
            };
            for (int i = 0; i < n; ++i) {
                int x = i + 1 < n ? maxs[i + 1] : -1;
                int y = nearst(a[i][0]);
                if (x != -1 || y != -1) {
                    ans = min(ans, abs(a[i][0] - max(x, y)));
                }
                if (x != -1) {
                    ans = min(ans, abs(a[i][0] - x));
                }
                optional.insert(a[i][1]);
            }
            for (int i = 0; i < n; ++i) {
                swap(a[i][0], a[i][1]);
            }
        }
        cout << ans << "\n";
    }
}

