/**
 *    author:  MaGnsi0
 *    created: 18.06.2023 12:15:50
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 6e5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        set<int64_t> c;
        vector<set<int64_t>> b(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            c.insert(a[i]);
            b[i].insert(a[i]);
            for (int64_t x : b[i + 1]) {
                int64_t y = x * a[i] / __gcd(x, a[i]);
                if (y > OO) { break; }
                c.insert(y);
                b[i].insert(y);
            }
        }
        int64_t ans = 1;
        while (c.count(ans)) { ans++; }
        cout << ans << "\n";
    }
}
