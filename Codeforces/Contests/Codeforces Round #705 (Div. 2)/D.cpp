/**
 *    author:  MaGnsi0
 *    created: 15.12.2021 22:03:59
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, OO = 1e8, MOD = 1e9 + 7;

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
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<multiset<int>> b(N);
    vector<map<int, int>> c(n);
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        for (long long j = 2; j * j <= x; ++j) {
            if (x % j == 0) {
                int cnt = 0;
                while (x % j == 0) {
                    x /= j;
                    cnt++;
                }
                b[j].insert(cnt);
                c[i][j] = cnt;
            }
        }
        if (x > 1) {
            b[x].insert(1);
            c[i][x] = 1;
        }
    }
    long long res = 1;
    for (int i = 1; i < N; ++i) {
        if ((int)b[i].size() == n) {
            res = res * power<long long>(i, *b[i].begin(), MOD) % MOD;
        }
    }
    for (int i = 0; i < q; ++i) {
        int k, x;
        cin >> k >> x;
        k--;
        for (long long j = 2; j * j <= x; ++j) {
            if (x % j == 0) {
                int cnt = 0;
                while (x % j == 0) {
                    x /= j;
                    cnt++;
                }
                int old = 0, mini = ((int)b[j].size() == n ? *b[j].begin() : 0);
                if (c[k].find(j) != c[k].end()) {
                    old = c[k][j];
                    b[j].erase(b[j].find(old));
                }
                c[k][j] = cnt + old;
                b[j].insert(c[k][j]);
                if ((int)b[j].size() == n) {
                    res = res * power<long long>(j, *b[j].begin() - mini, MOD) % MOD;
                }
            }
        }
        if (x > 1) {
            int old = 0, mini = ((int)b[x].size() == n ? *b[x].begin() : 0);
            if (c[k].find(x) != c[k].end()) {
                old = c[k][x];
                b[x].erase(b[x].find(old));
            }
            c[k][x] = old + 1;
            b[x].insert(c[k][x]);
            if ((int)b[x].size() == n) {
                res = res * power<long long>(x, *b[x].begin() - mini, MOD) % MOD;
            }
        }
        cout << res << "\n";
    }
}
