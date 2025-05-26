/**
 *    author:  MaGnsi0
 *    created: 26.05.2025 18:18:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> x(n), y(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }
        multiset<int64_t> X(x.begin(), x.end());
        multiset<int64_t> Y(y.begin(), y.end());
        function<int64_t()> find_answer = [&]() {
            int64_t min_x = *X.begin();
            int64_t max_x = *X.rbegin();
            int64_t min_y = *Y.begin();
            int64_t max_y = *Y.rbegin();
            int64_t lx = max_x - min_x + 1;
            int64_t ly = max_y - min_y + 1;
            if ((int)X.size() != n && lx * ly < n) {
                return min(lx * (ly + 1), (lx + 1) * ly);
            }
            return lx * ly;
        };
        int64_t ans = find_answer();
        for (int i = 0; i < n; ++i) {
            X.erase(X.find(x[i]));
            Y.erase(Y.find(y[i]));
            ans = min(ans, find_answer());
            X.insert(x[i]);
            Y.insert(y[i]);
        }
        cout << ans << "\n";
    }
}
