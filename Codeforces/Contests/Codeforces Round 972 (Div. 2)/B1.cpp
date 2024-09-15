/**
 *    author:  MaGnsi0
 *    created: 14.09.2024 17:41:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int Q; cin >> Q;
        set<int> a;
        for (int i = 0; i < m; ++i) {
            int x; cin >> x; a.insert(x);
        }
        while (Q--) {
            int x; cin >> x;
            auto it1 = a.lower_bound(x);
            if (it1 == a.begin()) {
                if (*it1 == x) {
                    cout << 0 << "\n";
                } else {
                    cout << *it1 - 1 << "\n";
                }
            } else if (it1 == a.end()) {
                it1--;
                cout << n - *it1 << "\n";
            } else {
                auto it2 = it1; it2--;
                cout << (*it1 - *it2) / 2 << "\n";
            }
        }
    }
}
