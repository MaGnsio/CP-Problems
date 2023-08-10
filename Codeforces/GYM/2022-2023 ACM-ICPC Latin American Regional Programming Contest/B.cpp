/**
 *    author:  MaGnsi0
 *    created: 20.07.2023 14:46:15
**/
#include <bits/stdc++.h>

using namespace std;

struct Line {
    mutable int64_t k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(int64_t x) const { return p < x; }
};
 
struct LineContainer : multiset<Line, less<>> {
    static const int64_t OO = LLONG_MAX;
    int64_t div(int64_t a, int64_t b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) { return x -> p = OO, 0; }
        if (x -> k == y -> k) {
            x -> p = x -> m > y -> m ? OO : -OO;
        } else {
            x -> p = div(y -> m - x -> m, x -> k - y -> k);
        }
        return x -> p >= y -> p;
    }
    void add(int64_t k, int64_t m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) { z = erase(z); }
        if (x != begin() && isect(--x, y)) { isect(x, y = erase(y)); }
        while ((y = x) != begin() && (--x) -> p >= y -> p) {
            isect(x, erase(y));
        }
    }
    int64_t query(int64_t x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> X(n), Y(n);
    for (int i = 0; i < n; ++i) {
        cin >> X[i] >> Y[i];
    }

    int m;
    cin >> m;
    vector<int> A(m), B(m);
    for (int i = 0; i < m; ++i) {
        cin >> A[i] >> B[i];
    }

    vector<LineContainer> S(4 * m);
    function<void(int, int, int)> build = [&](int j, int low, int high) {
        for (int i = low; i <= high; ++i) {
            S[j].add(A[i], B[i]);
        }
        if (low == high) { return; }
        int mid = (low + high) / 2;
        build(2 * j + 1, low, mid);
        build(2 * j + 2, mid + 1, high);
    };
    build(0, 0, m - 1);

    function<int(int, int, int, int)> Q = [&](int j, int low, int high, int p) {
        int64_t maxY = S[j].query(X[p]);
        if (maxY <= Y[p]) { return -1; }
        if (low == high) { return low; }
        int mid = (low + high) / 2;
        int64_t maxL = S[2 * j + 1].query(X[p]);
        if (maxL > Y[p]) {
            return Q(2 * j + 1, low, mid, p);
        } else {
            return Q(2 * j + 2, mid + 1, high, p);
        }
    };

    vector<vector<int>> ans(m);
    for (int i = 0; i < n; ++i) {
        int j = Q(0, 0, m - 1, i);
        if (j != -1) {
            ans[j].push_back(i + 1);
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << (int)ans[i].size();
        for (int j : ans[i]) {
            cout << " " << j;
        }
        cout << "\n";
    }
}
