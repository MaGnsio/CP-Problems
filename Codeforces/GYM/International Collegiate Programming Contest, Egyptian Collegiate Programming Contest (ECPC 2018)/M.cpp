/**
 *    author:  MaGnsi0
 *    created: 09.07.2023 23:04:59
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void remove(ordered_multiset<int> &t, int v){
    int rank = t.order_of_key(v);
    ordered_multiset<int>::iterator it = t.find_by_order(rank);
    t.erase(it);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("business.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> X1(n), Q(n), R(n);
        for (int i = 0; i < n; ++i) {
            cin >> X1[i] >> Q[i] >> R[i];
        }
        vector<int> X2(m), D(m);
        for (int i = 0; i < m; ++i) {
            cin >> X2[i] >> D[i];
        }
        map<int, array<vector<pair<int, int>>, 3>> mp;
        for (int i = 0; i < n; ++i) {
            mp[X1[i]][0].emplace_back(Q[i], X1[i]);
            mp[X1[i] + R[i] + 1][1].emplace_back(Q[i], X1[i]);
        }
        for (int i = 0; i < m; ++i) {
            mp[X2[i]][2].emplace_back(D[i], i); 
        }
        vector<int> ans(m);
        ordered_multiset<int> S;
        for (auto& [x, V] : mp) {
            for (auto& [q, x1] : V[0]) {
                S.insert(q - x1);
            }
            for (auto& [q, x1] : V[1]) {
                remove(S, q - x1);
            }
            for (auto& [d, j] : V[2]) {
                ans[j] = (int)S.size() - S.order_of_key(d - x);
            }
        }
        for (int i = 0; i < m; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
