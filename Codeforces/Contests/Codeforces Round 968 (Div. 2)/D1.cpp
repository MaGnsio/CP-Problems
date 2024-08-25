/**
 *    author:  MaGnsi0
 *    created: 25.08.2024 18:24:01
**/
#include <bits/stdc++.h>

using namespace std;

int64_t sum(int64_t l, int64_t r) {
    if (l > r) { return 0; }
    int64_t y = r * (r + 1) / 2;
    int64_t x = l * (l - 1) / 2;
    return y - x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t m; cin >> m;
        int64_t max_mex = 0;
        for (int i = 0; i < n; ++i) {
            int k; cin >> k;
            set<int> s;
            for (int j = 0; j < k; ++j) {
                int x; cin >> x; s.insert(x);
            }
            int64_t mex = 0;
            while ((int)s.count(mex)) { mex++; }
            mex++;
            while ((int)s.count(mex)) { mex++; }
            max_mex = max(max_mex, mex);
        }
        int64_t ans = min(max_mex + 1, m + 1) * max_mex + sum(max_mex + 1, m); 
        cout << ans << "\n";
    }
}
