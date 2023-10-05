/**
 *    author:  MaGnsi0
 *    created: 19.09.2023 21:21:02
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e12;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int k; cin >> k; k--;
    int m; cin >> m;
    int Q; cin >> Q;
    vector<int64_t> C(n);
    for (int i = 0; i < n; ++i) {
        cin >> C[i];
    }
    for (int i = 1; i < n; ++i) {
        C[i] += C[i - 1];
    }
    vector<int64_t> X(m + 1);
    for (int i = 0; i <= m; ++i) {
        cin >> X[i];
    }
    for (int i = 1; i <= m; ++i) {
        X[i] += X[i - 1];
    }
    set<int64_t> blockedC, blockedX;
    blockedC.insert(-1), blockedC.insert(OO);
    blockedX.insert(-1), blockedX.insert(OO);
    function<int64_t(int, int)> go_clockwise = [&](int u, int v) {
        if (u == v) { return int64_t(0); }
        if (u < v) {
            if (*blockedC.lower_bound(u) < v) {
                return OO;
            } else {
                return int64_t(C[v - 1] - (u ? C[u - 1] : 0LL));
            }
        } else {
            if (*blockedC.lower_bound(u) < n) {
                return OO;
            } else {
                return C[n - 1] - (u ? C[u - 1] : 0) + go_clockwise(0, v);
            }
        }
        assert(0);
        return OO;
    };
    function<int64_t(int, int)> go_short = [&](int u, int v) {
        if (u == v) { return int64_t(0); }
        if (u > v) { swap(u, v); }
        if (*blockedX.lower_bound(u) < v) {
            return OO;
        } else {
            return int64_t(X[v - 1] - (u ? X[u - 1] : 0LL));
        }
        assert(0);
        return OO;
    };
    function<int64_t(int, int)> F = [&](int u, int v) {
        int64_t ans = OO;
        ans = min(ans, go_clockwise(u, v));
        ans = min(ans, go_clockwise(v, u));
        vector<int> A = {u, v}, B = {0, k};
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                ans = min(ans, go_clockwise(A[i], B[j]) + go_short(0, m + 1) + go_clockwise(A[i ^ 1], B[j ^ 1]));
                ans = min(ans, go_clockwise(A[i], B[j]) + go_short(0, m + 1) + go_clockwise(B[j ^ 1], A[i ^ 1]));
                ans = min(ans, go_clockwise(B[j], A[i]) + go_short(0, m + 1) + go_clockwise(A[i ^ 1], B[j ^ 1]));
                ans = min(ans, go_clockwise(B[j], A[i]) + go_short(0, m + 1) + go_clockwise(B[j ^ 1], A[i ^ 1]));
            }
        }
        return ans;
    };
    while (Q--) {
        char type;
        cin >> type;
        if (type == 'c') {
            int c; cin >> c;
            if (blockedC.count(c - 1)) {
                blockedC.erase(c - 1);
            } else {
                blockedC.insert(c - 1);
            }
        } else if (type == 'x') {
            int x; cin >> x;
            if (blockedX.count(x)) {
                blockedX.erase(x);
            } else {
                blockedX.insert(x);
            }
        } else {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            if (0 <= u && u < n && 0 <= v && v < n) {
                int64_t ans = F(u, v);
                if (ans == OO) {
                    cout << "impossible\n";
                } else {
                    cout << ans << "\n";
                }
            } else if (u >= n && v >= n) {
                int64_t ans = OO;
                ans = min(ans, go_short(u - n + 1, v - n + 1));
                ans = min(ans, go_short(u - n + 1, 0) + go_clockwise(0, k) + go_short(m + 1, v - n + 1));
                ans = min(ans, go_short(v - n + 1, 0) + go_clockwise(0, k) + go_short(m + 1, u - n + 1));
                ans = min(ans, go_short(u - n + 1, 0) + go_clockwise(k, 0) + go_short(m + 1, v - n + 1));
                ans = min(ans, go_short(v - n + 1, 0) + go_clockwise(k, 0) + go_short(m + 1, u - n + 1));
                if (ans == OO) {
                    cout << "impossible\n";
                } else {
                    cout << ans << "\n";
                }
            } else {
                int64_t ans = OO;
                if (v < n) { swap(u, v); }
                ans = min(ans, go_short(v - n + 1, 0) + go_clockwise(0, u));
                ans = min(ans, go_short(v - n + 1, m + 1) + go_clockwise(k, u));
                ans = min(ans, go_short(v - n + 1, 0) + go_clockwise(u, 0));
                ans = min(ans, go_short(v - n + 1, m + 1) + go_clockwise(u, k));
                if (ans == OO) {
                    cout << "impossible\n";
                } else {
                    cout << ans << "\n";
                }
            }
        }
    }
}
