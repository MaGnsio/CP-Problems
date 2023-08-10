/**
 *    author:  MaGnsi0
 *    created: 25.02.2023 14:38:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    int64_t ans = 0;
    for (int x = 1; x <= N; ++x) {
        int yz = N - 3 * x;
        if (yz <= 0 || yz % 7) { continue; }
        yz /= 7;
        for (int y = 1; y * y <= yz; ++y) {
            if (yz % y == 0) {
                ans++;
                ans += y * y != yz;
            }
        }
    }
    cout << ans;
}
