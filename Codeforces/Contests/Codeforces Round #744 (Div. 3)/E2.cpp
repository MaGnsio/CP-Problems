/**
 *    author:  MaGnsi0
 *    created: 28/09/2021 16:19:17
**/
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        long long res = 0;
        ordered_multiset<int> big, small;
        for (int i = 0; i < n; ++i) {
            res += (long long)min(big.order_of_key(v[i]), small.order_of_key(-v[i]));
            big.insert(v[i]);
            small.insert(-v[i]);
        }
        cout << res << "\n";
    }
}
