/**
 *    author:  MaGnsi0
 *    created: 08.06.2024 16:28:11
**/
#include <bits/stdc++.h>

using namespace std;
using Node = array<int64_t, 5>;

const Node Zero = {};

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    vector<Node> a(4 * n, Zero);
    function<void(int, int, int)> push = [&](int j, int low, int high) {
        a[j][0] += a[j][1] * a[j][4] % MOD; a[j][0] %= MOD;
        a[j][0] += a[j][2] * a[j][3] % MOD; a[j][0] %= MOD;
        a[j][0] += a[j][3] * a[j][4] % MOD * (high - low + 1) % MOD; a[j][0] %= MOD;
        a[j][1] += a[j][3] * (high - low + 1) % MOD; a[j][1] %= MOD;
        a[j][2] += a[j][4] * (high - low + 1) % MOD; a[j][2] %= MOD;
        if (low != high) {
            a[2 * j + 1][3] += a[j][3]; a[2 * j + 1][3] %= MOD;
            a[2 * j + 1][4] += a[j][4]; a[2 * j + 1][4] %= MOD;
            a[2 * j + 2][3] += a[j][3]; a[2 * j + 2][3] %= MOD;
            a[2 * j + 2][4] += a[j][4]; a[2 * j + 2][4] %= MOD;        
        }
        a[j][3] = a[j][4] = 0;
    };
    function<Node(Node, Node)> F = [&](Node L, Node R) {
        assert(L[3] + L[4] == 0);
        assert(R[3] + R[4] == 0);
        Node res = Zero;
        res[0] = (L[0] + R[0]) % MOD;
        res[1] = (L[1] + R[1]) % MOD;
        res[2] = (L[2] + R[2]) % MOD;
        return res;
    };
    function<void(int, int, int, int, int, int, int64_t)> add_ = [&](int j, int low, int high, int from, int to, int i, int64_t x) {
        if (low > high) { return; }
        if (high < from || to < low) { return; }
        if (from <= low && high <= to) {
            a[j][i] += x;
            push(j, low, high);
            return;
        }
        push(j, low, high);
        int mid = (low + high) / 2;
        add_(2 * j + 1, low, mid, from, to, i, x);
        add_(2 * j + 2, mid + 1, high, from, to, i, x);
        push(2 * j + 1, low, mid);
        push(2 * j + 2, mid + 1, high);
        a[j] = F(a[2 * j + 1], a[2 * j + 2]);
    };
    function<void(int, int, int, int64_t)> add = [&](int from, int to, int i, int64_t x) {
        add_(0, 0, n - 1, from, to, i, x);
    };
    function<Node(int, int, int, int, int)> get_ = [&](int j, int low, int high, int from, int to) {
        if (low > high) { return Zero; }
        if (high < from || to < low) { return Zero; }
        push(j, low, high);
        if (from <= low && high <= to) { return a[j]; }
        int mid = (low + high) / 2;
        return F(get_(2 * j + 1, low, mid, from, to), get_(2 * j + 2, mid + 1, high, from, to));
    };
    function<int64_t(int, int)> get = [&](int from, int to) {
        return get_(0, 0, n - 1, from, to)[0];
    };
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        add(i, i, 3, x);
    }
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        add(i, i, 4, x);
    }
    while (Q--) {
        int t; cin >> t;
        int low; cin >> low; low--;
        int high; cin >> high; high--;
        if (t < 3) {
            int64_t x; cin >> x;
            add(low, high, t + 2, x);
        } else {
            cout << get(low, high) << "\n";
        }
    }
}
