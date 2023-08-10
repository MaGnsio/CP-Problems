/**
 *    author:  MaGnsi0
 *    created: 17.06.2023 16:04:09
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    ordered_set<int> all;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            all.insert(a[i][j]);
        }
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        ordered_set<int> cur;
        for (int j = 0; j < m; ++j) {
            cur.insert(a[i][j]);
            all.erase(a[i][j]);
        }
        for (int j = 0; j < m; ++j) {
            ans += all.order_of_key(a[i][j]) + int64_t(n - i - 1) * (cur.order_of_key(a[i][j]) + 1);
        }
    }
    cout << ans;
}
