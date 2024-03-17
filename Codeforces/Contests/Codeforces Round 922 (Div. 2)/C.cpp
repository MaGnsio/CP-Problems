/**
 *    author:  MaGnsi0
 *    created: 30.01.2024 16:45:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t a; cin >> a;
        int64_t b; cin >> b;
        int64_t r; cin >> r;
        int64_t x = 0, diff = 0;
        for (int bit = 60; bit >= 0; --bit) {
            if ((a >> bit & 1) == (b >> bit & 1)) { continue; }
            if (a >> bit & 1) {
                if (abs(diff + (1LL << bit)) <= abs(diff - (1LL << bit))) {
                    diff += 1LL << bit;
                } else if (x + (1LL << bit) <= r) {
                    diff -= 1LL << bit;
                    x += 1LL << bit;
                } else {
                    diff += 1LL << bit;
                }
            } else {
                if (abs(diff + (1LL << bit)) >= abs(diff - (1LL << bit))) {
                    diff -= 1LL << bit;
                } else if (x + (1LL << bit) <= r) {
                    diff += 1LL << bit;
                    x += 1LL << bit;
                } else {
                    diff -= 1LL << bit;
                }
            }
        }
        cout << abs((a ^ x) - (b ^ x)) << "\n";
    }
}
