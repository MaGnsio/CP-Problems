/**
 *    author:  MaGnsi0
 *    created: 15.09.2023 18:21:00
**/
#include <bits/stdc++.h>

using namespace std;

bool F(int64_t x, int64_t low, int64_t high) {
    if (x > high) { return false; }
    if (low <= x) { return true; }
    int64_t diff = low - x, have = 0, add = 0;
    for (int i = 40; i >= 0; --i) {
        if (x >> i & 1) { continue; }
        have |= (1LL << i); 
    }
    for (int i = 40; i >= 0; --i) {
        if (x >> i & 1) { continue; }
        have -= (1LL << i);
        if (have >= diff) { continue; }
        diff -= (1LL << i), add += (1LL << i);
    }
    assert(diff <= 0);
    assert((x & add) == 0);
    assert(low <= x + add);
    return (low <= x + add && x + add <= high);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int64_t> L(n), R(n);
        for (int i = 0; i < n; ++i) {
            cin >> L[i] >> R[i];
        }
        int64_t ans = 0;
        for (int i = 30; i >= 0; --i) {
            bool ok = true;
            for (int j = 0; j < n; ++j) {
                ok = ok && F(ans | (1LL << i), L[j], R[j]);
            }
            if (ok) { ans |= (1LL << i); }
        }
        cout << ans << "\n";
    }
}
