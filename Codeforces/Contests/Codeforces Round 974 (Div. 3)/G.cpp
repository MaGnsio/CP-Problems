/**
 *    author:  MaGnsi0
 *    created: 21.09.2024 19:23:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t m; cin >> m;
        int64_t k; cin >> k;
        vector<int64_t> d(n), a(n);
        for (int i = 0; i < n; ++i) {
            cin >> d[i] >> a[i];
        }
        int64_t ans = 0;
        vector<int64_t> left_overs_d, left_overs_a;
        for (int i = 0; i < n; ++i) {
            int64_t drink = min({(i == n - 1 ? INT64_MAX : m * (d[i + 1] - d[i])), k * m, m * (a[i] / m)});
            left_overs_d.push_back(d[i]);
            left_overs_a.push_back(a[i] - drink);
            int64_t have = 0;
            int64_t Ds = d[i] + drink / m;
            int64_t De = (i == n - 1 ? INT64_MAX : d[i + 1] - 1);
            ans += drink / m;
            while (!left_overs_d.empty()) {
                int j = (int)left_overs_d.size() - 1;
                if (Ds > De) { break; }
                if (Ds > left_overs_d[j] + k - 1) { break; }
                int64_t need = m - have;
                if (left_overs_a[j] < need) {
                    have += left_overs_a[j];
                    left_overs_a.pop_back();
                    left_overs_d.pop_back();
                } else {
                    left_overs_a[j] -= need; have = 0;
                    ans++; Ds++;
                }
            }
        }
        cout << ans << "\n";
    }
}
