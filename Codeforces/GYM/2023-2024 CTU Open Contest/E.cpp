/**
 *    author:  MaGnsi0
 *    created: 25.01.2024 21:12:57
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    map<int, ordered_multiset<int>> p;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        for (int j = 2; j * j <= x; ++j) {
            while (x % j == 0) {
                p[j].insert(i);
                x /= j;
            }
        }
        if (x > 1) { p[x].insert(i); }
    }
    int Q; cin >> Q;
    while (Q--) {
        int low; cin >> low; low--;
        int high; cin >> high; high--;
        int x; cin >> x;
        map<int, int> f;
        for (int j = 2; j * j <= x; ++j) {
            while (x % j == 0) {
                f[j]++;
                x /= j;
            }
        }
        if (x > 1) { f[x]++; }
        bool bad = false;
        for (auto [prime, y] : f) {
            bad |= (p[prime].order_of_key(high + 1) - p[prime].order_of_key(low)) < y;
        }
        cout << (bad ? "No" : "Yes") << "\n";
    }
}
