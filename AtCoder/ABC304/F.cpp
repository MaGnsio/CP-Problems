/**
 *    author:  MaGnsi0
 *    created: 03.06.2023 16:03:12
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<int64_t> P2(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        P2[i] = P2[i - 1] * 2;
        P2[i] %= MOD;
    }
    map<int64_t, int64_t> all;
    function<void(int64_t)> calc = [&](int64_t x) {
        string t(x, '.');
        for (int i = 0; i < n; ++i) {
            if (s[i] == '.') {
                t[i % x] = '#';
            }
        }
        int m = count(t.begin(), t.end(), '.');
        all[x] = P2[m];
    };
    for (int i = 1; i * i <= n; ++i) {
        if (n % i) { continue; }
        calc(i), calc(n / i);
    }
    all.erase(n);
    map<int64_t, int64_t> exact;
    for (auto [x, y] : all) {
        exact[x] = y;
        for (auto [xx, yy] : all) {
            if (x <= xx) { break; }
            if (x % xx == 0) {
                exact[x] -= exact[xx];
                exact[x] += MOD;
                exact[x] %= MOD;
            }
        }
    }
    int64_t ans = 0;
    for (auto [x, y] : exact) {
        ans += y;
        ans %= MOD;
    }
    cout << ans;
}
