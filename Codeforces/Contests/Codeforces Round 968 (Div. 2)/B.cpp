/**
 *    author:  MaGnsi0
 *    created: 25.08.2024 17:39:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        multiset<int> s;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; s.insert(x);
        }
        bool remove_min = true;
        while ((int)s.size() > 1) {
            if (remove_min) {
                s.erase(s.find(*s.begin()));
            } else {
                s.erase(s.find(*s.rbegin()));
            }
            remove_min ^= true;
        }
        cout << *s.begin() << "\n";
    }
}
