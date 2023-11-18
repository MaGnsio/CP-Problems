/**
 *    author:  MaGnsi0
 *    created: 15.10.2023 23:39:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<tuple<int, int, int>> a(n), b(m);
        for (int i = 0; i < n; ++i) {
            int x1; cin >> x1;
            int x2; cin >> x2;
            int y; cin >> y;
            if (x1 > x2) { swap(x1, x2); }
            a[i] = make_tuple(y, x1, x2);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < m; ++i) {
            int y1; cin >> y1;
            int y2; cin >> y2;
            int x; cin >> x;
            if (y1 > y2) { swap(y1, y2); }
            b[i] = make_tuple(x, y1, y2);
        }
        function<bool(int)> F = [&](int M) {
            vector<pair<int, int>> add_x;
            vector<pair<int, int>> rem_x;
            multiset<int> good_x;
            for (auto [x, y1, y2] : b) {
                if (y1 + M > y2 - M) { continue; }
                add_x.emplace_back(y1 + M, x);
                rem_x.emplace_back(y2 - M + 1, x);
            }
            sort(add_x.begin(), add_x.end());
            sort(rem_x.begin(), rem_x.end());
            int i = 0, j = 0;
            for (auto [y, x1, x2] : a) {
                int low = x1 + M;
                int high = x2 - M;
                if (low > high) { continue; }
                while (i < (int)add_x.size() && add_x[i].first <= y) {
                    good_x.insert(add_x[i++].second);
                }
                while (j < (int)rem_x.size() && rem_x[j].first <= y) {
                    good_x.erase(good_x.find(rem_x[j++].second));
                }
                if (good_x.lower_bound(low) != good_x.end() && *good_x.lower_bound(low) <= high) {
                    return true;
                }
            }
            return false;
        };
        int low = 0, high = 1e5, ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (F(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}
