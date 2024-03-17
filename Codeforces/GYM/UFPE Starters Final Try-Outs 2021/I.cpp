/**
 *    author:  MaGnsi0
 *    created: 10.02.2024 14:19:50
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
    int Q; cin >> Q;
    int n; cin >> n;
    vector<int64_t> ans(n);
    ordered_set<pair<int64_t, int>> S;
    for (int i = 0; i < n; ++i) {
        S.insert(make_pair(ans[i], i));
    }
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int j; cin >> j;
            int64_t x; cin >> x;
            S.erase(make_pair(ans[j], j));
            ans[j] += x;
            S.insert(make_pair(ans[j], j));
        } else {
            int64_t k; cin >> k;
            cout << n - S.order_of_key(make_pair(k + 1, -1)) << "\n";
        }
    }
}
