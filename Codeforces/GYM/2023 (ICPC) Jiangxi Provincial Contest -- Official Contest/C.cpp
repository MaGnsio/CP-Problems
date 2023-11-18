/**
 *    author:  MaGnsi0
 *    created: 10.11.2023 19:29:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int64_t p; cin >> p;
    int64_t nimber = 0;
    for (int i = 0; i < n; ++i) {
        int64_t x; cin >> x;
        if (p & 1) {
            nimber ^= (x % 2);
        } else {
            int64_t m = x % (p + 1);
            if (m == p) {
                nimber ^= 2;
            } else if (m & 1) {
                nimber ^= 1;
            } else {
                nimber ^= 0;
            }
        }
    }
    cout << (nimber ? "GOOD" : "BAD");
}
