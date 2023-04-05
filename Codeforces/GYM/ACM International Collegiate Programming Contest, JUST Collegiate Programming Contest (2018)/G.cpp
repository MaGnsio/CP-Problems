/**
 *    author:  MaGnsi0
 *    created: 25.01.2023 00:24:55
**/
#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b, int m) {
    a %= m, b %= m;
    int k = 1, add = 0, g;
    if (a == 0) { return (b == 0 ? 1 : -1); }
    while ((g = __gcd(a, m)) > 1) {
        if (b == k) { return add; }
        if (b % g) { return -1; }
        b /= g, m /= g, add++;
        k = (1LL * k * a / g) % m;
    }
    int n = sqrt(m) + 1, an = 1;
    for (int i = 0; i < n; ++i) {
        an = (1LL * an * a) % m;
    }
    unordered_map<int, int> vals;
    for (int q = 0, cur = b; q <= n; ++q) {
        vals[cur] = q;
        cur = (1LL * cur * a) % m;
    }
    for (int p = 1, cur = k; p <= n; ++p) {
        cur = (cur * 1ll * an) % m;
        if (vals.count(cur)) {
            int ans = n * p - vals[cur] + add;
            return ans;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a, b, m;
        cin >> a >> b >> m;
        cout << solve(a, b, m) << "\n";
    }
}
