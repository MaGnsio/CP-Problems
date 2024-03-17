/**
 *    author:  MaGnsi0
 *    created: 28.12.2023 18:16:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t sum = 0;
        for (int i = 0; i < n; ++i) {
            int64_t x; cin >> x; sum += x;
        }
        int64_t y = sqrt(sum);
        cout << (y * y == sum ? "YES" : "NO") << "\n";
    }
}
