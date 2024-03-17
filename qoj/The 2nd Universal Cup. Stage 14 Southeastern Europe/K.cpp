/**
 *    author:  MaGnsi0
 *    created: 07.02.2024 20:52:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        multiset<pair<int, int>> sums;
        vector<int> ans(n);
        for (int i = 0; i < k; ++i) {
            sums.emplace(0, i + 1);
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                auto [sum, j] = *sums.begin();
                sums.erase(sums.begin());
                sums.emplace(sum + 1, j);
                ans[i] = j;
            } else {
                auto [sum, j] = *sums.rbegin();
                auto it = sums.find(make_pair(sum, j));
                sums.erase(it);
                sums.emplace(max(sum - 1, 0), j);
                ans[i] = j;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
