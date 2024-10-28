/**
 *    author:  MaGnsi0
 *    created: 28.10.2024 18:45:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n; cin >> n;
    vector<int64_t> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    b[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        b[i] = b[i + 1] + a[i] * (n - i);
    }
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] * (n - i);
    }
    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
        c[i] += c[i - 1];
    }
    function<int64_t(int, int)> getA = [&](int l, int r) {
        if (l > r) { return int64_t(0); }
        return a[r] - (l ? a[l - 1] : 0);
    };
    function<int64_t(int, int)> getB = [&](int l, int r) {
        if (l > r) { return int64_t(0); }
        return b[r] - (l ? b[l - 1] : 0);
    };
    function<int64_t(int, int)> getC = [&](int l, int r) {
        if (l > r) { return int64_t(0); }
        return c[r] - (l ? c[l - 1] : 0);
    };
    vector<int> start(n);
    for (int64_t i = 0, s = 0; i < n; ++i) {
        start[i] = s;
        s += (n - i);
    }
    function<int64_t(int64_t)> getI = [&](int64_t i) {
        int64_t I = int64_t(lower_bound(start.begin(), start.end(), i) - start.begin());
        return start[I] == i ? I : I - 1;
    };
    function<int64_t(int64_t, int64_t)> getB_from_start_to = [&](int64_t j, int64_t r) {
        int64_t i = start[j];
        if (i > r) { return int64_t(0); }
        int64_t k = j + (r - i);
        assert(0 <= k && k < n);
        int64_t sum = getC(j, k) - ((n - j) - (k - j + 1)) * getA(j, k);
        return sum;
    };
    function<int64_t(int64_t, int64_t)> solve = [&](int64_t l, int64_t r) {
        int64_t i = getI(l), j = getI(r);
        if (i == j) {
            return getB_from_start_to(i, r) - getB_from_start_to(i, l - 1);
        }
        return (getB(i, i) - getB_from_start_to(i, l - 1)) + getB(i + 1, j - 1) + getB_from_start_to(j, r);
    };
    int Q; cin >> Q;
    while (Q--) {
        int64_t l; cin >> l; l--;
        int64_t r; cin >> r; r--;
        int64_t ans = solve(l, r);
        cout << ans << "\n";
    }
}
