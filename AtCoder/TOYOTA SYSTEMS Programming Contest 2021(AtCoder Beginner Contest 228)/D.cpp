/**
 *    author:  MaGnsi0
 *    created: 20.11.2021 14:23:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> q, n = (1 << 20);
    vector<long long> a(n, -1);
    set<long long> todo;
    for (int i = 0; i < n; ++i) {
        todo.insert(i);
    }
    while (q--) {
        long long t, x;
        cin >> t >> x;
        if (t == 1) {
            auto it = todo.lower_bound(x % n);
            if (it == todo.end()) {
                it = todo.begin();
            }
            a[*it] = x;
            todo.erase(it);
        } else {
            cout << a[x % n] << "\n";
        }
    }
}
