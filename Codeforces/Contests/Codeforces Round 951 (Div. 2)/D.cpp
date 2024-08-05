/**
 *    author:  MaGnsi0
 *    created: 06.06.2024 18:19:23
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const array<int64_t, 2> B = {31, 53};
const array<int64_t, 2> MOD = {int64_t(1e9 + 7), int64_t(1e9 + 9)};
 
vector<array<int64_t, 2>> P(N);
vector<array<int64_t, 2>> P_(N);
 
struct H {
    int len;
    array<int64_t, 2> hash;
    H() {}
    H(char c) {
        len = 1;
        for (int i = 0; i < 2; ++i) {
            hash[i] = (c - '0');
        }
    }
};
 
H F(H x, H y) {
    H z;
    z.len = x.len + y.len;
    for (int i = 0; i < 2; ++i) {
        z.hash[i] = (x.hash[i] + P[x.len][i] * y.hash[i]) % MOD[i];
    }
    return z;
}

int64_t power(int64_t b, int64_t p, int64_t mod) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % mod; }
        b = b * b % mod;
        p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    P[0][0] = P[0][1] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 2; ++j) {
            P[i][j] = P[i - 1][j] * B[j] % MOD[j];
            P_[i][j] = power(P[i][j], MOD[j] - 2, MOD[j]);
        }
    }
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        string s; cin >> s;
        vector<H> pre(n), suf(n);
        pre[0] = H(s[0]);
        for (int i = 1; i < n; ++i) {
            pre[i] = F(pre[i - 1], H(s[i]));
        }
        suf[n - 1] = H(s[n - 1]);
        for (int i = n - 2; i >= 0; --i) {
            suf[i] = F(suf[i + 1], H(s[i]));
        }
        string s1 = "", s2 = "";
        for (int i = 0, j = 0; i < n / k; ++i, j ^= 1) {
            for (int x = 0; x < k; ++x) { s1 += char('0' + j); }
        }
        for (int i = 0, j = 1; i < n / k; ++i, j ^= 1) {
            for (int x = 0; x < k; ++x) { s2 += char('0' + j); }
        }
        H good1(s1[0]), good2(s2[0]);
        for (int i = 1; i < n; ++i) {
            good1 = F(good1, H(s1[i]));
            good2 = F(good2, H(s2[i]));
        }
        function<H(int, int)> get = [&](int l, int r) {
            if (l == 0) { return pre[r]; }
            H res = pre[r];
            res.len -= pre[l - 1].len;
            for (int j = 0; j < 2; ++j) {
                res.hash[j] -= pre[l - 1].hash[j];
                res.hash[j] += MOD[j]; res.hash[j] %= MOD[j];
                res.hash[j] *= P_[pre[l - 1].len][j];
                res.hash[j] %= MOD[j];
            }
            return res;
        };
        function<H(int, int)> get_reverse = [&](int l, int r) {
            if (r == n - 1) { return suf[l]; }
            H res = suf[l];
            res.len -= suf[r + 1].len;
            for (int j = 0; j < 2; ++j) {
                res.hash[j] -= suf[r + 1].hash[j];
                res.hash[j] += MOD[j]; res.hash[j] %= MOD[j];
                res.hash[j] *= P_[suf[r + 1].len][j];
                res.hash[j] %= MOD[j];
            }
            return res;
        };
        int ans = -1;
        if (get_reverse(0, n - 1).hash == good1.hash || get_reverse(0, n - 1).hash == good2.hash) {
            cout << n << "\n";
            continue;
        }
        for (int p = 1; p < n; ++p) {
            H L = get(p, n - 1);
            H R = get_reverse(0, p - 1);
            H X = F(L, R);
            if (X.hash == good1.hash || X.hash == good2.hash) {
                ans = p;
                break;
            }
        }
        cout << ans << "\n";

    }
}
