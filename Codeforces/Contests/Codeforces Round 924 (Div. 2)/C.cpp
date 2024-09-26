/**
 *    author:  MaGnsi0
 *    created: 26.09.2024 20:00:55
**/
#include <bits/stdc++.h>

using namespace std;

set<int> F(int64_t x, int64_t f, bool equal = true) {
    set<int> res;
    for (int64_t i = 1; i * i <= f; ++i) {
        if (f % i) { continue; }
        if ((i % 2 == 0) && (equal ? (i + 2) / 2 >= x : (i + 2) / 2 > x)) {
            res.insert((i + 2) / 2);
        }
        int j = f / i;
        if ((j % 2 == 0) && (equal ? (j + 2) / 2 >= x : (j + 2) / 2 > x)) {
            res.insert((j + 2) / 2);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t x; cin >> x;
        set<int> ans = F(x, n - x);
        for (int k : F(x, n + x - 2, false)) {
            ans.insert(k);
        }
        cout << (int)ans.size() << "\n";
    }
}
