/**
 *    author:  MaGnsi0
 *    created: 06.05.2023 17:04:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int64_t>> a(2);
        for (int i = 0; i < n; ++i) {
            int64_t x;
            cin >> x;
            a[x % 2].push_back(x);
        }
        int64_t ans = accumulate(a[0].begin(), a[0].end(), int64_t(0));
        sort(a[1].rbegin(), a[1].rend());
        for (int i = 0; i < (int)a[1].size(); i += 2) {
            if (i + 1 < (int)a[1].size()) {
                ans += a[1][i] + a[1][i + 1];
            }
        }
        cout << (ans ? ans : -1) << "\n";
    }
}
