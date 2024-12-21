/**
 *    author:  MaGnsi0
 *    created: 21.12.2024 19:59:35
**/
#include <bits/stdc++.h>

using namespace std;

int64_t C(int64_t n, int64_t k) {
    int64_t ans = 1;
    for (int64_t i = 1; i <= n; ++i) {
        ans *= i;
    }
    for (int64_t i = 1; i <= k; ++i) {
        ans /= i;
    }
    for (int64_t i = 1; i <= (n - k); ++i) {
        ans /= i;
    }
    return ans;
}

int64_t stars_and_bars(int64_t stars, int64_t bars) {
    return C(stars + bars - 1, stars);

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string n; cin >> n;
        int64_t ans = 1;
        for (char c : n) {
            int x = c - '0';
            ans *= stars_and_bars(x, 3);
        }
        cout << ans << "\n";
    }
}
