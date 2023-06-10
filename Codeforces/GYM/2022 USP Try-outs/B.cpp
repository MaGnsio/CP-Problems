/**
 *    author:  MaGnsi0
 *    created: 03.06.2023 00:05:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t C, X, T, N;
    cin >> C >> X >> T >> N;
    vector<int64_t> t(3);
    for (int i = 0; i < 3; ++i) {
        cin >> t[i];
    }
    vector<vector<int64_t>> a(3);
    for (int i = 0; i < N; ++i) {
        int x, j;
        cin >> x >> j;
        a[j - 1].push_back(x);
    }
    for (int i = 0; i < 3; ++i) {
        sort(a[i].begin(), a[i].end());
    }
    function<int64_t(int64_t, int64_t)> G = [&](int64_t f, int64_t x) {
        int64_t time = f + X * ((x - f) / X);
        if (x == time && time - X >= f) { time -= X; }
        return time;
    };
    function<bool(int64_t, int64_t)> F = [&](int64_t j, int64_t x) {
        int64_t m = (int)a[j].size() + 1, L = 0, c = 0, k = N + 2;
        vector<int64_t> leaves, b = a[j];
        b.push_back(x);
        sort(b.begin(), b.end());
        for (int i = 0; i < m; ++i) {
            if (c == C) {
                leaves.push_back(b[i - 1]);
                L = G(b[i - 1], b[i]);
                c = 0;
            }
            if (b[i] - L > X) {
                leaves.push_back(L + X);
                L = G(L + X, b[i]);
                c = 0;
            }
            if (b[i] == x) {
                k = min(k, (int64_t)leaves.size());
            }
            c++;
            if (i == m - 1) {
                leaves.push_back((c == C ? b[i] : L + X));
            }
        }
        return leaves[k] + t[j] <= T;
    };
    function<bool(int64_t)> ok = [&](int64_t x) {
        for (int i = 0; i < 3; ++i) {
            if (F(i, x)) { return true; }
        }
        return false;
    };
    int64_t low = 0, high = T, ans = 0;
    while (low <= high) {
        int64_t mid = (low + high) / 2;
        if (ok(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans;
}
