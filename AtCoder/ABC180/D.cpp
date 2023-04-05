/**
 *    author:  MaGnsi0
 *    created: 09.11.2022 21:07:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t X, Y, A, B;
    cin >> X >> Y >> A >> B;
    int64_t ans = 0;
    for (int64_t i = 0; X < Y; ++i) {
        ans = max(ans, int64_t(i + (Y - X - 1) / B));
        if (X >= Y / A) {
            break;
        }
        X *= A;
    }
    cout << ans;
}
