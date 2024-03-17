/**
 *    author:  MaGnsi0
 *    created: 28.12.2023 18:44:14
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
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        iota(c.begin(), c.end(), 0);
        sort(c.begin(), c.end(), [&](int i, int j) {
                return a[i] > a[j];
            });
        int64_t ans = 0;
        ordered_set<int> s;
        for (int j : c) {
            ans += s.order_of_key(b[j]);
            ans -= s.order_of_key(a[j]);
            s.insert(b[j]);
        }
        cout << ans << "\n";
    }
}
