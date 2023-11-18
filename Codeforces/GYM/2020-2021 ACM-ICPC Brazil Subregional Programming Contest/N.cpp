/**
 *    author:  MaGnsi0
 *    created: 24.10.2023 06:52:49
**/
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull modmul(ull a, ull b, ull M) {
    long long ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (long long)M);
}

ull modpow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2) {
        if (e & 1) { ans = modmul(ans, b, mod); }
    }
    return ans;
}

bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1) { return (n | 1) == 3; }
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    ull s = __builtin_ctzll(n - 1), d = n >> s;
    for (ull a : A) {
        ull p = modpow(a % n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--) {
            p = modmul(p, p, n);
        }
        if (p != n - 1 && i != s) { return 0; }
    }
    return 1;
}

ull pollard(ull n) {
    auto f = [n](ull x) { return modmul(x, x, n) + 1; };
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    while (t++ % 40 || __gcd(prd, n) == 1) {
        if (x == y) { x = ++i, y = f(x); }
        if ((q = modmul(prd, max(x, y) - min(x, y), n))) { prd = q; }
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}

vector<ull> factor(ull n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    ull x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), r.begin(), r.end());
    return l;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m; cin >> m;
    int n; cin >> n;
    int k; cin >> k;
    set<ull> ans;
    for (int i = 0; i < n; ++i) {
        ull x; cin >> x;
        vector<ull> f = factor(x);
        for (auto& y : f) { ans.insert(y); }
    }
    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        int y; cin >> y;
        int z; cin >> z;
    }
    for (auto& x : ans) {
        cout << x << " ";
    }
}
