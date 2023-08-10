/**
 *    author:  MaGnsi0
 *    created: 14.06.2023 02:52:01
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int P10[5] = {1, 10, 100, 1000, 10000};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = (int)s.size();
        vector<ordered_set<int>> a(5);
        for (int i = 0; i < n; ++i) {
            a[s[i] - 'A'].insert(i);
        }
        function<int(int)> F = [&](int x) {
            int j = -1;
            for (int i = x + 1; i < 5; ++i) {
                if (a[i].empty()) { continue; }
                j = max(j, *a[i].rbegin());
            }
            int m = (int)a[x].size() - 2 * a[x].order_of_key(j);
            return m * P10[x];
        };
        function<int()> G = [&]() {
            int ans = 0;
            for (int i = 0; i < 5; ++i) {
                ans += F(i);
            }
            return ans;
        };
        int ans = G();
        for (int i = 0; i < n; ++i) {
            a[s[i] - 'A'].erase(i);
            for (int j = 0; j < 5; ++j) {
                a[j].insert(i);
                ans = max(ans, G());
                a[j].erase(i);
            }
            a[s[i] - 'A'].insert(i);
        }
        cout << ans << "\n";
    }
}
