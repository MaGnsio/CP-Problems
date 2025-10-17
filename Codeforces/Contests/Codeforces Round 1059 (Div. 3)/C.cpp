/**
 *    author:  MaGnsi0
 *    created: 17.10.2025 17:45:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t x; cin >> x;
        int64_t y; cin >> y;
        bool ok = true;
        vector<int64_t> ops;
        for (int b = 33; b >= 0; --b) {
            if ((x >> b & 1) == (y >> b & 1)) { continue; }
            if (x >> b & 1) { continue; }
            int64_t z = 1LL << b;
            if (z > x) { ok = false; break; }
            x ^= z;
            ops.push_back(z);
        }
        for (int b = 33; b >= 0; --b) {
            if ((x >> b & 1) == (y >> b & 1)) { continue; }
            int64_t z = 1LL << b;
            if (z > x) { ok = false; break; }
            x ^= z;
            ops.push_back(z);
        }
        if (ok) {
            cout << (int)ops.size() << "\n";
            for (int64_t x : ops) {
                cout << x << " ";
            }
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }
}
