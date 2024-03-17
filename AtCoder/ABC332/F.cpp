/**
 *    author:  MaGnsi0
 *    created: 10.12.2023 18:21:57
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int M; cin >> M;
    vector<int64_t> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<int64_t> a(4 * N, 0), b(4 * N, 0), c(4 * N, 1);
    function<void(int)> push = [&](int j) {
        a[2 * j + 1] *= c[j]; a[2 * j + 1] %= MOD;
        c[2 * j + 1] *= c[j]; c[2 * j + 1] %= MOD;
        a[2 * j + 2] *= c[j]; a[2 * j + 2] %= MOD;
        c[2 * j + 2] *= c[j]; c[2 * j + 2] %= MOD;
        b[2 * j + 1] *= c[j]; b[2 * j + 1] %= MOD;
        b[2 * j + 2] *= c[j]; b[2 * j + 2] %= MOD;
        a[2 * j + 1] += b[j]; a[2 * j + 1] %= MOD;
        b[2 * j + 1] += b[j]; b[2 * j + 1] %= MOD;
        a[2 * j + 2] += b[j]; a[2 * j + 2] %= MOD;
        b[2 * j + 2] += b[j]; b[2 * j + 2] %= MOD;
        b[j] = 0, c[j] = 1;
    };
    function<void(int, int, int, int, int, int64_t, bool)> update = [&](int j, int low, int high, int from, int to, int64_t x, bool is_add) {
        if (low > high) { return; }
        if (high < from || to < low) { return; }
        if (low != high) { push(j); }
        if (from <= low && high <= to) {
            if (is_add) {
                a[j] += x; a[j] %= MOD;
                b[j] += x; b[j] %= MOD;
            } else {
                a[j] *= x; a[j] %= MOD;
                c[j] *= x; c[j] %= MOD;
            }
            if (low != high) { push(j); }
            return;
        }
        int mid = (low + high) / 2;
        update(2 * j + 1, low, mid, from, to, x, is_add);
        update(2 * j + 2, mid + 1, high, from, to, x, is_add);
        a[j] = (a[2 * j + 1] + a[2 * j + 2]) % MOD;
    };
    function<int64_t(int, int, int, int, int)> query = [&](int j, int low, int high, int from, int to) {
        if (low > high) { return int64_t(0); }
        if (high < from || to < low) { return int64_t(0); }
        if (from <= low && high <= to) { return a[j]; }
        push(j);
        int mid = (low + high) / 2;
        return (query(2 * j + 1, low, mid, from, to) + query(2 * j + 2, mid + 1, high, from, to)) % MOD;
    };
    function<int64_t(int64_t, int64_t)> power = [&](int64_t b, int64_t p) {
        int64_t res = 1;
        while (p) {
            if (p & 1) { res = res * b % MOD; }
            b = b * b % MOD;
            p /= 2;
        }
        return res;
    };
    for (int i = 0; i < N; ++i) {
        update(0, 0, N - 1, i, i, A[i], true);
    }
    while (M--) {
        int from; cin >> from; from--;
        int to; cin >> to; to--;
        int64_t x; cin >> x;
        int64_t p = power(to - from + 1, MOD - 2);
        int64_t np = (1 - p + MOD) % MOD;
        update(0, 0, N - 1, from, to, np, false); 
        update(0, 0, N - 1, from, to, p * x % MOD, true);
    }
    for (int i = 0; i < N; ++i) {
        cout << query(0, 0, N - 1, i, i) << " ";
    }
}
