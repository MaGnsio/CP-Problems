/**
 *    author:  MaGnsi0
 *    created: 19.10.2024 15:05:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    int L = 1, R = 2;
    int64_t ans = 0;
    while (Q--) {
        char h; cin >> h;
        int p; cin >> p;
        int add = INT_MAX;
        if (h == 'L') {
            if (min(L, p) <= R && R <= max(L, p)) {
                add = min(add, n - abs(L - p));
            } else {
                add = min(add, abs(L - p));
            }
            L = p;
        } else {
            if (min(R, p) <= L && L <= max(R, p)) {
                add = min(add, n - abs(R - p));
            } else {
                add = min(add, abs(R - p));
            }
            R = p;
        }
        ans += add;
    }
    cout << ans;
}
