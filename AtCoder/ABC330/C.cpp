/**
 *    author:  MaGnsi0
 *    created: 25.11.2023 22:15:02
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t d; cin >> d;
    int64_t ans = INT64_MAX;
    for (int64_t x = 0; x < N; ++x) {
        int64_t need = max(d - x * x, int64_t(0));
        int64_t y = sqrt(need);
        ans = min(ans, abs(x * x + y * y - d)); 
        y++;
        ans = min(ans, abs(x * x + y * y - d));
    }
    cout << ans;
}
