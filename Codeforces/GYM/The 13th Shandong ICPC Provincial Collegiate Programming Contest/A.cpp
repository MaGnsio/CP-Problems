/**
 *    author:  MaGnsi0
 *    created: 13.10.2023 19:27:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, k;
        cin >> n >> k;
        map<int64_t, int64_t> a;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            int y; cin >> y;
            a[x] += y;
        }
        int64_t sum = 0;
        bool ok = true;
        for (auto [x, y] : a) {
            sum += y;
            ok = ok && sum <= x * k;
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }
}
