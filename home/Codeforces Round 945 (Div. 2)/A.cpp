/**
 *    author:  MaGnsi0
 *    created: 19.05.2024 16:24:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int p1; cin >> p1;
        int p2; cin >> p2;
        int p3; cin >> p3;
        int ans = -1;
        for (int p12 = 0; p12 <= p1; ++p12) {
            for (int p13 = 0; p13 <= p1; ++p13) {
                for (int p23 = 0; p23 <= p2; ++p23) {
                    int p1_ = p1 - (p12 + p13);
                    int p2_ = p2 - (p12 + p23);
                    int p3_ = p3 - (p13 + p23);
                    if ((p1_ < 0) || (p2_ < 0) || (p3_ < 0)) { continue; } 
                    if ((p1_ & 1) || (p2_ & 1) || (p3_ & 1)) { continue; }
                    ans = max(ans, p12 + p13 + p23);
                }
            }
        }
        cout << ans << "\n";
    }
}
