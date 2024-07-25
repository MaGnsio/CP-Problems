/**
 *    author:  MaGnsi0
 *    created: 25.07.2024 16:13:13
**/
#include <bits/stdc++.h>

using namespace std;

const int B = 31;

struct node {
    int zeros, ones;
    node() {
        zeros = ones = 0;
    }
};

struct segment_tree {
    int n;
    vector<int> L;
    vector<node> T;
    segment_tree(int n) : n(n), T(4 * n, node()), L(4 * n, 0) {}
    node F(node l, node r) {
        node res;
        res.zeros = l.zeros + r.zeros;
        res.ones = l.ones + r.ones;
        return res;
    }
    void init(int j, int low, int high) {
        if (low > high) { return; }
        if (low == high) {
            T[j] = node(); T[j].zeros = 1;
            return;
        }
        int mid = (low + high) / 2;
        init(2 * j + 1, low, mid);
        init(2 * j + 2, mid + 1, high);
        T[j] = F(T[2 * j + 1], T[2 * j + 2]);
    }
    void push(int j, int l, int r) {
        if (l == r) { return; }
        int m = (l + r) / 2;
        if (L[j]) {
            swap(T[2 * j + 1].ones, T[2 * j + 1].zeros);
            swap(T[2 * j + 2].ones, T[2 * j + 2].zeros);
        }
        L[2 * j + 1] ^= L[j];
        L[2 * j + 2] ^= L[j];
        L[j] = 0;
        return;
    }
    void update_(int j, int low, int high, int from, int to) {
        if (low > high) { return; }
        if (high < from || to < low) { return; }
        if (from <= low && high <= to) {
            swap(T[j].ones, T[j].zeros);
            L[j] ^= 1;
            push(j, low, high);
            return;
        }
        push(j, low, high);
        int mid = (low + high) / 2;
        update_(2 * j + 1, low, mid, from, to);
        update_(2 * j + 2, mid + 1, high, from, to);
        T[j] = F(T[2 * j + 1], T[2 * j + 2]);
    }
    node get_(int j, int low, int high, int from, int to) {
        if (low > high) { return node(); }
        if (high < from || to < low) { return node(); }
        if (from <= low && high <= to) { return T[j]; }
        push(j, low, high);
        int mid = (low + high) / 2;
        return F(get_(2 * j + 1, low, mid, from, to), get_(2 * j + 2, mid + 1, high, from, to));
    }
    void update(int from, int to) {
        update_(0, 0, n - 1, from, to);
    }
    node get(int from, int to) {
        return get_(0, 0, n - 1, from, to);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<segment_tree> s(B, segment_tree(n));
    for (int b = 0; b < B; ++b) {
        s[b].init(0, 0, n - 1);
    }
    for (int i = 0; i < n; ++i) {
        for (int b = 0; b < B; ++b) {
            if (a[i] >> b & 1) {
                s[b].update(i, i);
            }
        }
    }
    function<int64_t(int, int)> F = [&](int l, int r) {
        int64_t res = 0;
        for (int b = 0; b < B; ++b) {
            res += (1LL << b) * s[b].get(l, r).ones;
        }
        return res;
    };
    int Q; cin >> Q;
    while (Q--) {
        int t; cin >> t;
        int l; cin >> l; l--;
        int r; cin >> r; r--;
        if (t == 1) {
            cout << F(l, r) << "\n";
        } else {
            int x; cin >> x;
            for (int b = 0; b < B; ++b) {
                if (x >> b & 1) {
                    s[b].update(l, r);
                }
            }
        }
    }
}
