/**
 *    author:  MaGnsi0
 *    created: 05.04.2024 01:58:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t ans = 0;
        vector<int> a, b;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (x == 0) { continue; }
            if (x < 0) {
                a.push_back(-x);
                b.push_back(i);
                continue;
            }
            int start = i;
            while (x && !a.empty()) {
                int j = b.back(), minus = min(x, a.back());
                ans += 1LL * x * (start - j) * (n - i);
                x -= minus;
                if (a.back() == minus) {
                    a.pop_back();
                    b.pop_back();
                } else {
                    a.back() -= minus;
                }
                start = j;
            }
            ans += 1LL * x * (start + 1) * (n - i);
        }
        cout << ans << "\n";
    }
}
