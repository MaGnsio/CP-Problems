/**
 *    author:  MaGnsi0
 *    created: 23.08.2022 13:43:20
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

template <typename T>
T power(T b, T p, T m) {
    T res = 1;
    while (p) {
        if (p & 1) {
            res = ((res % m) * (b % m)) % m;
        }
        b = ((b % m) * (b % m)) % m;
        p >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s, w;
    cin >> s >> w;
    int con1 = 0, con2 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?' || w[i] == '?') {
            continue;
        }
        con1 += (s[i] < w[i]);
        con2 += (s[i] > w[i]);
    }
    int x = count(s.begin(), s.end(), '?');
    int y = count(w.begin(), w.end(), '?');
    int z = 0;
    for (int i = 0; i < n; ++i) {
        z += (s[i] == '?' && w[i] == '?');
    }
    int64_t ans = power<int64_t>(10, x + y, MOD);
    if (con1 && con2) {
        cout << ans;
        return 0;
    }
    int64_t comparable = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?' && w[i] == '?') {
            comparable *= 55;
            comparable %= MOD;
        } else if (s[i] == '?') {
            if (con1) {
                comparable *= w[i] - '0' + 1;
                comparable %= MOD;
            } else {
                comparable *= '9' - w[i] + 1;
            }
        } else if (w[i] == '?') {
            if (con1) {
                comparable *= '9' - s[i] + 1;
                comparable %= MOD;
            } else {
                comparable *= s[i] - '0' + 1;
                comparable %= MOD;
            }
        }
    }
    if (!con1 && !con2) {
        int64_t comparable2 = 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?' && w[i] == '?') {
                comparable2 *= 55;
                comparable2 %= MOD;
            } else if (s[i] == '?') {
                comparable2 *= w[i] - '0' + 1;
                comparable2 %= MOD;
            } else if (w[i] == '?') {
                comparable2 *= '9' - s[i] + 1;
                comparable2 %= MOD;
            }
        }
        comparable += comparable2;
        comparable -= power<int64_t>(10, z, MOD);
        comparable += MOD;
        comparable %= MOD;
    }
    ans -= comparable;
    ans += MOD;
    ans %= MOD;
    cout << ans;
}
