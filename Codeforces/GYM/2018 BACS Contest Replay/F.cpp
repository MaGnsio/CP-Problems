/**
 *    author:  MaGnsi0
 *    created: 20.10.2023 17:34:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        int k; cin >> k;
        int Q; cin >> Q;
        int holes = 1;
        set<int> S1, S2; 
        function<bool(int)> in = [&](int x) {
            if (x < 1) { return true; }
            if (x > n) { return true; }
            if (x <= k) {
                return S1.count(x) == 0;
            }
            return S2.count(x) == 1;
        };
        function<void(int)> add = [&](int x) {
            if (x <= k) {
                S1.erase(x);
            } else {
                S2.insert(x);
            }
        };
        function<void(int)> remove = [&](int x) {
            if (x <= k) {
                S1.insert(x);
            } else {
                S2.erase(x);
            }
        };
        cout << "Case " << t << ":\n";
        while (Q--) {
            int x; cin >> x;
            int y; cin >> y;
            if (!in(x - 1) && !in(x + 1)) {
                holes--;
            } else if (in(x - 1) && in(x + 1)) {
                holes++;
            }
            remove(x), add(y);
            if (!in(y - 1) && !in(y + 1)) {
                holes++;
            } else if (in(y - 1) && in(y + 1)) {
                holes--;
            }
            cout << holes << "\n";
        }
    }
}
