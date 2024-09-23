/**
 *    author:  MaGnsi0
 *    created: 23.09.2024 20:13:45
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

/*
 * order_of_key (k) : Number of items strictly smaller than k.
 * find_by_order(k) : K-th element in a set (counting from zero).
 */

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    string s; cin >> s;
    ordered_set<pair<int, char>> S;
    map<char, set<int>> mp;
    for (int i = 0; i < n; ++i) {
        S.insert({i, s[i]});
        mp[s[i]].insert(i);
    }
    while (m--) {
        int l; cin >> l; l--;
        int r; cin >> r; r--;
        char c; cin >> c;
        l = S.find_by_order(l) -> first;
        r = S.find_by_order(r) -> first;
        while (true) {
            auto it = mp[c].lower_bound(l);
            if (it == mp[c].end()) { break; }
            if (*it > r) { break; }
            S.erase({*it, c});
            mp[c].erase(it);
        }
    }
    for (auto [_, c] : S) {
        cout << c;
    }
    cout << "\n";
}
