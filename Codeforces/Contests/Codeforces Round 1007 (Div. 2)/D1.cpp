/**
 *    author:  MaGnsi0
 *    created: 28.02.2025 18:39:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t x; cin >> x; cin >> x;
        vector<int> a(n), p(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; p[i] = a[i] ^ (i ? p[i - 1] : 0);
        }
        if (n % 2 == 0) {
            a.push_back(p[n / 2 - 1]);
            p.push_back(a[n] ^ p[n - 1]);
            n++;
        }
        function<int(int64_t)> F = [&](int64_t x) {
            if (x <= n) { return a[x - 1]; }
            int64_t y = x / 2;
            if (y <= n) { return p[y - 1]; }
            return y & 1 ? p[n - 1] : F(y) ^ p[n - 1];
        };
        cout << F(x) << "\n";
    }
}

