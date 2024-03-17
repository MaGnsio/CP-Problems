/**
 *    author:  MaGnsi0
 *    created: 18.12.2023 15:15:36
**/
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
private:
    int N;
    vector<int64_t> T, L;
    void push(int j, int low, int high) {
        if (L[j] == -1) { return; }
        if (low != high) {
            int mid = (low + high) / 2;
            T[2 * j + 1] = (mid - low + 1) * L[j];
            L[2 * j + 1] = L[j];
            T[2 * j + 2] = (high - mid) * L[j];
            L[2 * j + 2] = L[j];
        }
        L[j] = -1;
    }
    void update(int j, int low, int high, int from, int to, int64_t x) {
        if (low > high) { return; }
        if (to < low || high < from) { return; }
        if (from <= low && high <= to) {
            T[j] = (high - low + 1) * x, L[j] = x;
            push(j, low, high);
        } else {
            push(j, low, high);
            int mid = (low + high) / 2;
            update(2 * j + 1, low, mid, from, to, x);
            update(2 * j + 2, mid + 1, high, from, to, x);
            T[j] = T[2 * j + 1] + T[2 * j + 2];
        }
    }
    int64_t query(int j, int low, int high, int from, int to) {
        if (low > high) { return 0; }
        if (to < low || high < from) { return 0; }
        if (from <= low && high <= to) { return T[j]; }
        push(j, low, high);
        int mid = (low + high) / 2;
        return query(2 * j + 1, low, mid, from, to) + query(2 * j + 2, mid + 1, high, from, to);
    }
public:
    segment_tree(int n) {
        N = n;
        T.assign(4 * N, 0);
        L.assign(4 * N, -1);
    }
    void set(int from, int to, int x) {
        update(0, 0, N - 1, from, to, x);
    }
    int64_t sum(int from, int to) {
        return query(0, 0, N - 1, from, to);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        vector<int> mexs(n), f(n + 1);
        for (int i = 0, mex = 0; i < n; ++i) {
            f[p[i]]++;
            while (f[mex]) { mex++; }
            mexs[i] = mex;
        }
        sort(mexs.begin(), mexs.end());
        segment_tree a(2 * n), b(n + 1);
        for (int i = 0; i < n; ++i) {
            a.set(i, i, mexs[i]);
            int val = b.sum(mexs[i], mexs[i]) + 1;
            b.set(mexs[i], mexs[i], val);
        }
        int64_t ans = a.sum(0, 2 * n - 1);
        for (int i = 0, k = 0; i < n; ++i) {
            //all mexs > p[i] become p[i]
            //all mexs < p[i] doesn't change
            int low = 0, high = n + k - 1;
            int j = n + k - b.sum(p[i], n);
            if (j != n + k) {
                a.set(j, n + k - 1, p[i]);
                a.set(n + k, n + k, n);
                b.set(p[i], n, 0);
                b.set(p[i], p[i], n + k - j);
                b.set(n, n, 1);
                k++;
            }
            ans = max(ans, a.sum(0, 2 * n - 1));
        }
        cout << ans << "\n";
    }
}
