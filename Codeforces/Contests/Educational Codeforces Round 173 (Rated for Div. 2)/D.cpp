/**
 *    author:  MaGnsi0
 *    created: 24.12.2024 19:23:21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t l; cin >> l;
        int64_t r; cin >> r;
        int64_t G; cin >> G;
        int64_t L = (l + G - 1) / G;
        int64_t R = r / G;
        if (L > R) {
            cout << -1 << " " << -1 << "\n";
        } else if (L == R && L != 1) {
            cout << -1 << " " << -1 << "\n";
        } else if (L == R) {
            cout << G << " " << " " << G << "\n";
        } else {
            int64_t A = L, B = L + 1;
            for (int64_t a = L; a <= R && a <= L + 4; ++a) {
                for (int64_t b = R; b >= L && b >= R - 4; --b) {
                    if (__gcd(a, b) == 1 && (B - A) < (b - a)) {
                        A = a, B = b;
                    }
                }
            }
            cout << A * G << " " << B * G << "\n";
        }
    }
}
