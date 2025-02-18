/**
 *    author:  MaGnsi0
 *    created: 18.02.2025 17:21:36
**/
#include <bits/stdc++.h>

using namespace std;

const int A = 26, N = 2e5 + 5;
const array<int64_t, 2> BASE = {31, 53};
const array<int64_t, 2> MOD = {int64_t(1e9 + 7), int64_t(1e9 + 9)};

vector<array<int64_t, 2>> P(N), P_(N);

int64_t power(int64_t b, int64_t p, int64_t mod) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % mod; }
        b = b * b % mod;
        p /= 2;
    }
    return res;
}

void init() {
    for (int j = 0; j < 2; ++j) {
        P[0][j] = P_[0][j] = 1;
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 2; ++j) {
            P[i][j] = P[i - 1][j] * BASE[j] % MOD[j];
            P_[i][j] = power(P[i][j], MOD[j] - 2, MOD[j]);
        }
    }
}

struct Hash {
    int n; string s;
    vector<array<int64_t, 2>> prefix;

    Hash(string s) {
        n = (int)s.size();
        this -> s = s;
        prefix.resize(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (i == 0) {
                    prefix[i][j] = s[i] - 'a';
                } else {
                    prefix[i][j] = (prefix[i - 1][j] + P[i][j] * (s[i] - 'a') % MOD[j]) % MOD[j];
                }
            }
        }
    }

    array<int64_t, 2> get(int l, int r) {
        array<int64_t, 2> res = {0, 0};
        for (int j = 0; j < 2; ++j) {
            res[j] = prefix[r][j];
            if (l) {
                res[j] -= prefix[l - 1][j]; res[j] += MOD[j]; res[j] %= MOD[j];
            }
            res[j] *= P_[l][j]; res[j] %= MOD[j];
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = (int)s.size();
        vector f(A, vector<int>(n, 0));
        for (int j = 0; j < n; ++j) {
            f[s[j] - 'a'][j]++;
        }
        for (int i = 0; i < A; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] += f[i][j - 1];
            }
        }
        Hash H1(s);
        reverse(s.begin(), s.end());
        Hash H2(s);
        function<bool(int, int, int, int)> ok1 = [&](int l1, int r1, int l2, int r2) {
            if (l1 > r1 || l2 > r2) { return true; }
            for (int i = 0; i < A; ++i) {
                int x = f[i][r1] - (l1 ? f[i][l1 - 1] : 0);
                int y = f[i][r2] - (l2 ? f[i][l2 - 1] : 0);
                if (x != y) { return false; }
            }
            return true;
        };
        function<bool(int, int, int, int)> ok2 = [&](int l1, int r1, int l2, int r2) {
            if (l1 > r1 || l2 > r2) { return true; }
            return H1.get(l1, r1) == H2.get(l1, r1);
        };
        function<bool(int, int, int, int)> ok3 = [&](int l1, int r1, int l2, int r2) {
            if (l1 > r1 && l2 > r2) { return true; }
            if (l2 > r2) { return false; }
            for (int i = 0; i < A; ++i) {
                int x = (l1 > l2 ? 0 : (f[i][r1] - (l1 ? f[i][l1 - 1] : 0)));
                int y = f[i][r2] - (l2 ? f[i][l2 - 1] : 0);
                if (x > y) { return false; }
                if ((y - x) & 1) { return false; }
            }
            return true;
        };
        function<bool(int)> F = [&](int x) {
            for (int i = 0; i + x - 1 < n / 2; ++i) {
                if (ok1(i, i + x - 1, n - i - x, n - i - 1) && ok2(0, i - 1, n - i, n - 1) && ok2(i + x, n / 2 - 1, n / 2, n - i - x - 1)) {
                    return true;
                }
            }
            return false;
        };
        function<bool(int)> F_ = [&](int x) {
            for (int i = (n / 2) - x + 1; i + x - 1 < n; ++i) {
                int m = min(i, n - (i + x - 1) - 1);
                if (!ok2(0, m - 1, 0, m - 1)) { continue; }
                if (i > n - (i + x - 1) - 1) {
                    if (ok3(m, i - 1, i, i + x - 1)) { return true; }
                } else {
                    if (ok3(i + x, n - m - 1, i, i + x - 1)) { return true; }
                }
            }
            return false;
        };
        if (H1.get(0, n - 1) == H2.get(0, n - 1)) {
            cout << 0 << "\n";
            continue;
        }
        int low = 2, high = n / 2, ans = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (F(mid)) {
                ans = mid; high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        low = 2, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (F_(mid)) {
                ans = min(ans, mid), high = mid - 1;
            } else {
                low = mid + 1;
            }

        }
        cout << ans << "\n";
    }
}
