/**
 *    author:  MaGnsi0
 *    created: 19.08.2024 20:27:45
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const array<int64_t, 2> B = {31, 53};
const array<int64_t, 2> MOD = {int64_t(1e9 + 7), int64_t(1e9 + 9)};
 
vector<array<int64_t, 2>> P(N);
vector<array<int64_t, 2>> P_(N);

struct Hash {
    int size;
    array<int64_t, 2> H;
    Hash() { size = H[0] = H[1] = 0; }
    Hash(char c) {
        size = 1;
        for (int j = 0; j < 2; ++j) {
            H[j] = (c - 'a');
        }
    }
};
 
Hash F(Hash x, Hash y) {
    Hash z;
    z.size = x.size + y.size;
    for (int j = 0; j < 2; ++j) {
        z.H[j] = (x.H[j] + P[x.size][j] * y.H[j]) % MOD[j];
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

void __init__() {
    P[0][0] = P[0][1] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 2; ++j) {
            P[i][j] = P[i - 1][j] * B[j] % MOD[j];
            P_[i][j] = power(P[i][j], MOD[j] - 2, MOD[j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    __init__();
    int n; cin >> n;
    string s; cin >> s;
    vector<int> C(n);
    for (int i = 0; i < n; ++i) {
        C[i] = (s[i] == 'A' ? 1 : -1);
    }
    for (int i = 1; i < n; ++i) {
        C[i] += C[i - 1];
    }
    vector<string> S(2, "");
    for (int i = 0, x1 = 0, x2 = 0; i < n; ++i) {
        x1 += (s[i] == 'A' ? 1 : -1);
        x2 += (i ? (s[i] == 'A' ? 1 : -1) : 0);
        S[0] += (x1 == 0 ? "c" : (x1 > 0 ? "a" : "b"));
        S[1] += (i ? (x2 == 0 ? "c" : (x2 > 0 ? "a" : "b")) : "*");
    }
    vector<vector<Hash>> a(2, vector<Hash>(n));
    for (int i = 0; i < n; ++i) {
        a[0][i] = F((i == 0 ? Hash() : a[0][i - 1]), Hash(S[0][i]));
        if (i == 0) { continue; }
        a[1][i] = F((i == 1 ? Hash() : a[1][i - 1]), Hash(S[1][i]));
    }
    function<Hash(int)> get = [&](int i) {
        if (i == n) { return Hash(); }
        Hash res = a[0][n - 1];
        res.size = n - i;
        if (i == 0) { return res; }
        for (int j = 0; j < 2; ++j) {
            res.H[j] -= a[0][i - 1].H[j];
            res.H[j] += MOD[j]; res.H[j] %= MOD[j];
            res.H[j] *= P_[i][j]; res.H[j] %= MOD[j];
        }
        return res;
    };
    set<array<int64_t, 2>> unique;
    for (int i = 0; i < n; ++i) {
        Hash L = a[1][i];
        Hash M = (C[i] == 0 ? Hash('c') : (C[i] > 0 ? Hash('a') : Hash('b')));
        Hash R = get(i + 1);
        unique.insert(F(F(L, M), R).H);
    }
    int ans = (int)unique.size();
    cout << ans;
}
