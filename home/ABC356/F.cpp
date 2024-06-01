/**
 *    author:  MaGnsi0
 *    created: 01.06.2024 16:17:18
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
    int64_t k; cin >> k;
    ordered_set<int64_t> S, D;
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int64_t x; cin >> x;
            if (S.find(x) != S.end()) {
                auto it = S.find(x);
                auto itL = it; itL--;
                auto itR = it; itR++;
                int64_t prv = (it == S.begin() ? -1 : *itL); 
                int64_t nxt = (itR == S.end() ? -1 : *itR);
                S.erase(it); D.erase(x);
                if (nxt == -1 || prv == -1) { continue; }
                if (nxt - prv > k) { D.insert(prv); }
            } else {
                if (S.empty()) {
                    S.insert(x);
                    continue;
                }
                auto itR = S.lower_bound(x);
                auto itL = itR; itL--;
                int64_t prv = (itR == S.begin() ? -1 : *itL); 
                int64_t nxt = (itR == S.end() ? -1 : *itR);
                D.erase(prv);
                if (prv != -1 && x - prv > k) { D.insert(prv); }
                if (nxt != -1 && nxt - x > k) { D.insert(x); }
                S.insert(x);
            }
        } else {
            int64_t x; cin >> x;
            if (D.empty()) {
                cout << (int)S.size() << "\n";
                continue;
            }
            auto itR = D.lower_bound(x);
            auto itL = itR; itL--;
            int ans = (itR == D.end() ? (int)S.size() : S.order_of_key(*itR + 1));
            ans -= (itR == D.begin() ? 0 : S.order_of_key(*itL + 1));
            cout << ans << "\n";
        }
    }
}
