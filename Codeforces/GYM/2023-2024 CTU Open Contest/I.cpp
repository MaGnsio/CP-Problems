/**
 *    author:  MaGnsi0
 *    created: 25.01.2024 19:23:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t C; cin >> C;
    int n; cin >> n;
    set<int64_t> S;
    for (int i = 0; i < n; ++i) {
        int64_t x; cin >> x;
        S.insert(x);
    }
    for (int64_t x : S) {
        if (C % x) { continue; }
        assert(S.count(C / x) == 1);
        cout << x << " " << C / x;
        return 0;
    }
}
