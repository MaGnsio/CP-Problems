/**
 *    author:  MaGnsi0
 *    created: 01.08.2022 01:29:28
**/
#include <bits/stdc++.h>

using namespace std;

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

template <typename T>
T bsgs(T a, T b, T m) {
    a %= m, b %= m;
    T n = sqrt(m) + 1;
    map<T, T> vals;
    for (T p = 1; p <= n; ++p) {
        vals[power(a, p * n, m)] = p;
    }
    for (T q = 0; q <= n; ++q) {
        T cur = (power(a, q, m) * b) % m;
        if (vals.count(cur)) {
            T ans = vals[cur] * n - q;
            return ans;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t a, b, m, x0, x;
    cin >> a >> b >> m >> x0 >> x;
    assert(a < m && b < m && x0 < m && x < m);
    /*
     * X[n] = a * X[n - 1] + b
     *      = a^2 * X[n - 2] + a * b + b
     *      = . . . = a^n * X[0] + b * (1 + a + a^2 + ... + a^(n-1))
     *      = a^n * X[0] + b * (1 - a^n) / (1 - a)
     * let a^n = y -> X[n] = y * X[0] + b * (1 - y) / (1 - a)
     *                     = y * X[0] + b / (1 - a) - by / (1 - a)
     *                     = y * {X[0] - b / (1 - a)} + b / (1 - a)
     *    -> (X[n] * (1 - a) - b) / (X[0] * (1 - a) - b) = y = a^n
     *    -> ((a - 1) * X[n] + b) / ((a - 1) * X[0] + b) = y = a^n 
     * Corner Cases:-
     *  - X[n] == X[0]
     *  - a = 1
     *      - b == 0
     *      - b != 0
     *  - a = 0
     */
    if (x == x0) {
        cout << "YES";
    } else if (a == 0) {
        cout << (x == b ? "YES" : "NO");
    } else if (a == 1) {
        if (b == 0) {
            cout << (x == x0 ? "YES" : "NO");
        } else {
            //X[n] = X[0] + k * b 
            // -> (X[n] - X[0]) / b = k
            cout << "YES";
        }
    } else {
        int64_t L = (x * (a - 1) + b) % m;
        L *= power<int64_t>((x0 * (a - 1) + b) % m, m - 2, m);
        L %= m;
        cout << (bsgs(a, L, m) != -1 ? "YES" : "NO");
    }
}
