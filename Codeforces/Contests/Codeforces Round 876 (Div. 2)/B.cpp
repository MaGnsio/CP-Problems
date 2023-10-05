/**
 *    author:  MaGnsi0
 *    created: 03.06.2023 17:50:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, vector<int64_t>> mp;
        for (int i = 0; i < n; ++i) {
            int64_t x, y;
            cin >> x >> y;
            mp[x].push_back(y);
        }
        int64_t ans = 0;
        for (auto& [x, a] : mp) {
            sort(a.rbegin(), a.rend());
            a.resize(min((int)a.size(), x));
            for (auto& y : a) {
                ans += y;
            }
        }
        cout << ans << "\n";
    }
}
