/**
 *    author:  MaGnsi0
 *    created: 10.02.2024 15:37:38
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const array<int64_t, 2> B = {31, 53};
const array<int64_t, 2> MOD = {int64_t(1e9 + 7), int64_t(1e9 + 9)};

vector<array<int64_t, 2>> P(N);

struct H {
    int len;
    array<int64_t, 2> hash;
    H() {}
    H(char c) {
        len = 1;
        for (int i = 0; i < 2; ++i) {
            hash[i] = (c - 'a');
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

template <typename T>
struct segment_tree {
    int N;
    T E;
    vector<T> S;
    function<T(T, T)> F;
    segment_tree(int n, T e, function<T(T, T)> f) : N(n), E(e), S(2 * n, e), F(f) {}
    void update(int j, T x) {
        for (S[j += N] = x; j /= 2;) {
            S[j] = F(S[2 * j], S[2 * j + 1]);
        }
    }
    T query(int L, int R) {
        T l = E, r = E;
        for (L += N, R += N; L < R; L /= 2, R /= 2) {
            if (L % 2) {
                l = F(l, S[L++]);
            }
            if (R % 2) {
                r = F(S[--R], r);
            }
        }
        return F(l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    P[0][0] = P[0][1] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 2; ++j) {
            P[i][j] = P[i - 1][j] * B[j] % MOD[j];
        }
    }
    H O; O.len = O.hash[0] = O.hash[1] = 0;
    int n; cin >> n;
    int Q; cin >> Q;
    vector<int> lens(n);
    vector<segment_tree<H>> a(n, segment_tree<H>(1, O, F));
    vector<segment_tree<H>> b(n, segment_tree<H>(1, O, F));
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        lens[i] = (int)s.size();
        a[i] = segment_tree<H>(lens[i], O, F);
        b[i] = segment_tree<H>(lens[i], O, F);
        for (int j = 0; j < lens[i]; ++j) {
            a[i].update(j, H(s[j]));
            b[i].update(lens[i] - j - 1, H(s[j]));
        }
    }
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int i; cin >> i; i--;
            int j; cin >> j; j--;
            char c; cin >> c;
            a[i].update(j, H(c));
            b[i].update(lens[i] - j - 1, H(c));
        } else if (t == 2) {
            int i; cin >> i; i--;
            int j; cin >> j; j--;
            int L1; cin >> L1; L1--;
            int R1; cin >> R1;
            int L2; cin >> L2; L2--;
            int R2; cin >> R2;
            cout << (a[i].query(L1, R1).hash == a[j].query(L2, R2).hash ? "equal" : "different") << "\n"; 
        } else {
            int i; cin >> i; i--;
            int j; cin >> j; j--;
            int L1; cin >> L1; L1--;
            int R1; cin >> R1; R1--;
            int L2; cin >> L2; L2--;
            int R2; cin >> R2; R2--;
            int m1 = lens[i], m2 = lens[j];
            H x = F(a[i].query(L1, R1 + 1), a[j].query(L2, R2 + 1));
            H y = F(b[j].query(m2 - R2 - 1, m2 - L2), b[i].query(m1 - R1 - 1, m1 - L1));
            cout << (x.hash == y.hash ? "cool" : "not so cool") << "\n";
        }
    }
}
