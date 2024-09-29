/**
 *    author:  MaGnsi0
 *    created: 29.09.2024 18:56:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t a = 0;
        int64_t b; cin >> b;
        int64_t c; cin >> c;
        int64_t d; cin >> d;
        for (int b_ = 0; b_ < 62; ++b_) {
            if ((b >> b_ & 1) != (c >> b_ & 1)) { continue; }
            if ((b >> b_ & 1) != (d >> b_ & 1)) {
                a |= 1LL << b_;
            }
        }
        if ((a | b) - (a & c) != d) {
            cout << -1 << "\n";
        } else {
            cout << a << "\n";
        }
    }
}
