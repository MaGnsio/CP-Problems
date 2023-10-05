/**
 *    author:  MaGnsi0
 *    created: 26.08.2023 19:22:32
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353, M = 32;

const array<int, 3> O = {-1, -1, 0};

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return res;
}

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
        int64_t ans = 0;
        vector<array<int, 3>> T(1, O);
        function<void(int64_t)> insert = [&](int64_t x) {
            int j = 0;
            for (int B = M - 1; B >= 0; --B) {
                int b = (x >> B & 1);
                if (T[j][b] == -1) {
                    T[j][b] = (int)T.size();
                    T.push_back(O);
                }
                j = T[j][b]; T[j][2]++;
            }
        };
        function<void(int64_t)> add = [&](int64_t x) {
            int j = 0, s = 0;
            for (int B = M - 1; B >= 0; --B) {
                int b = (x >> B & 1); s += b;
                int y = (T[j][!b] == -1 ? 0 : T[T[j][!b]][2]);
                if (b) {
                    ans += int64_t(s + (s & 1)) * y;
                    ans %= MOD;
                } else {
                    ans += int64_t(s + (s & 1) + 1) * y;
                    ans %= MOD;
                }
                j = T[j][b];
            }
            ans += int64_t(s + 1) * T[j][2] % MOD;
            ans %= MOD;
        };
        for (int i = 0; i < n; ++i) {
            insert(a[i]);
        }
        for (int i = 0; i < n; ++i) {
            add(a[i]);
        }
        ans = ans * power(n * n % MOD, MOD - 2) % MOD;
        cout << ans << "\n";
    }
}
