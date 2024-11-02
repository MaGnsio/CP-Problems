/**
 *    author:  MaGnsi0
 *    created: 02.11.2024 21:58:03
**/
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

const int B = 20, N = 1e5 + 5, MOD = 1e9 + 7;

vector<int> P2(N, 1);

struct xor_basis {
    array<int, B> basis;
    xor_basis() { basis.fill(0); }
    xor_basis(int x) {
        basis.fill(0);
        for (int b = B - 1; b >= 0; --b) {
            if (x >> b & 1) {
                basis[b] = x;
                break;
            }
        }
    }
    bool can(int x) {
        for (int b = B - 1; b >= 0; --b) {
            if (!(x >> b & 1)) { continue; }
            if (!basis[b]) { return false; }
            x ^= basis[b];
        }
        return true;
    }
};

xor_basis F(xor_basis basisA, xor_basis basisB) {
    xor_basis basisC;
    basisC.basis = basisA.basis;
    for (int& base : basisB.basis) {
        if (!base) { continue; }
        for (int b = B - 1; b >= 0; --b) {
            if (!(base >> b & 1)) { continue; }
            if (!basisC.basis[b]) {
                basisC.basis[b] = base;
                break;
            }
            base ^= basisC.basis[b];
        }
    }
    return basisC;
}

xor_basis G(xor_basis basisA, int x) {
    xor_basis basisB;
    for (int& base : basisA.basis) {
        base &= x;
        if (!base) { continue; }
        for (int b = B - 1; b >= 0; --b) {
            if (!(base >> b & 1)) { continue; }
            if (!basisB.basis[b]) {
                basisB.basis[b] = base;
                break;
            }
            base ^= basisB.basis[b];
        }
    }
    return basisB;
}

struct segment_tree {
    int n;
    vector<int> L;
    vector<xor_basis> T;
    segment_tree(int n) : n(n), L(4 * n, (1 << B) - 1), T(4 * n, xor_basis()) {}
    void push(int j) {
        T[2 * j + 1] = G(T[2 * j + 1], L[j]);
        T[2 * j + 2] = G(T[2 * j + 2], L[j]);
        L[2 * j + 1] &= L[j];
        L[2 * j + 2] &= L[j];
        L[j] = (1 << B) - 1;
    }
    void set_(int j, int low, int high, int pos, int x) {
        if (low > high) { return; }
        if (pos < low || high < pos) { return; }
        if (low == high) {
            T[j] = xor_basis(x);
            L[j] = (1 << B) - 1;
            return;
        }
        push(j);
        int mid = (low + high) / 2;
        set_(2 * j + 1, low, mid, pos, x);
        set_(2 * j + 2, mid + 1, high, pos, x);
        T[j] = F(T[2 * j + 1], T[2 * j + 2]);
    }
    void update_(int j, int low, int high, int from, int to, int x) {
        if (low > high) { return; }
        if (to < low || high < from) { return; }
        if (from <= low && high <= to) {
            T[j] = G(T[j], x);
            L[j] &= x;
            if (low != high) { push(j); }
            return;
        }
        push(j);
        int mid = (low + high) / 2;
        update_(2 * j + 1, low, mid, from, to, x);
        update_(2 * j + 2, mid + 1, high, from, to, x);
        T[j] = F(T[2 * j + 1], T[2 * j + 2]);
    }
    xor_basis get_(int j, int low, int high, int from, int to) {
        if (low > high) { return xor_basis(); }
        if (to < low || high < from) { return xor_basis(); }
        if (from <= low && high <= to) { return T[j]; }
        push(j);
        int mid = (low + high) / 2;
        return F(get_(2 * j + 1, low, mid, from, to), get_(2 * j + 2, mid + 1, high, from, to));
    }
    void set(int pos, int x) {
        set_(0, 0, n - 1, pos, x);
    }
    void update(int from, int to, int x) {
        update_(0, 0, n - 1, from, to, x);
    }
    int64_t get(int from, int to, int x) {
        xor_basis range_basis = get_(0, 0, n - 1, from, to);
        int64_t p = to - from + 1;
        if (!range_basis.can(x)) { return 0; }
        for (int& base : range_basis.basis) {
            p -= base != 0;
        }
        return P2[p];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 1; i < N; ++i) {
        P2[i] = P2[i - 1] * 2 % MOD;
    }
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        segment_tree a(n);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; a.set(i, x);
        }
        int Q; cin >> Q;
        while (Q--) {
            int t; cin >> t;
            if (t == 1) {
                int l; cin >> l; l--;
                int r; cin >> r; r--;
                int x; cin >> x;
                a.update(l, r, x);
            } else if (t == 2) {
                int j; cin >> j; j--;
                int x; cin >> x;
                a.set(j, x);
            } else {
                int l; cin >> l; l--;
                int r; cin >> r; r--;
                int x; cin >> x;
                cout << a.get(l, r, x) << "\n";
            }
        }
    }
}
