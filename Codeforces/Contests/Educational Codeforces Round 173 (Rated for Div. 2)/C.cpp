/**
 *    author:  MaGnsi0
 *    created: 24.12.2024 16:53:24
**/
#include <bits/stdc++.h>

using namespace std;

set<int64_t> solve1(vector<int64_t> a, int l, int r) {
    int n = r - l + 1;
    if (n < 1) { return set<int64_t>{0}; }
    vector<int64_t> b(a.begin() + l, a.begin() + r + 1);
    for (int i = 1; i < n; ++i) {
        b[i] += b[i - 1];
    }
    int64_t O = n, minp = 0, maxp = 0;
    vector<int64_t> have(2 * n + 2, 0); have[O]++; have[O + 1]--;
    for (int i = 0; i < n; ++i) {
        int64_t low = b[i] - maxp + O;
        int64_t high = b[i] - minp + O;
        have[low]++, have[high + 1]--;
        minp = min(minp, b[i]);
        maxp = max(maxp, b[i]);
    }
    for (int i = 1; i < 2 * n + 2; ++i) {
        have[i] += have[i - 1];
    }
    set<int64_t> res;
    for (int i = 0; i < 2 * n + 2; ++i) {
        if (have[i]) { res.insert(i - O); }
    }
    return res;
}

set<int64_t> solve2(vector<int64_t> a, int x) {
    int64_t minp1 = 0, maxp1 = 0;
    int64_t minp2 = 0, maxp2 = 0;
    for (int64_t i = x + 1, curp = 0; i < (int)a.size(); ++i) {
        curp += a[i];
        minp1 = min(minp1, curp);
        maxp1 = max(maxp1, curp);
    }
    for (int64_t i = x - 1, curp = 0; i >= 0; --i) {
        curp += a[i];
        minp2 = min(minp2, curp);
        maxp2 = max(maxp2, curp);
    }
    int64_t l = minp1 + minp2 + a[x];
    int64_t r = maxp1 + maxp2 + a[x];
    set<int64_t> res;
    for (int64_t i = l; i <= r; ++i) {
        res.insert(i);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n, x = -1; cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] != -1 && a[i] != 1) { x = i; }
        }
        set<int64_t> ans;
        if (x == -1) {
            auto s1 = solve1(a, 0, n - 1);
            ans.insert(s1.begin(), s1.end());
        } else {
            auto s1 = solve1(a, 0, x - 1);
            ans.insert(s1.begin(), s1.end());
            auto s2 = solve1(a, x + 1, n - 1);
            ans.insert(s2.begin(), s2.end());
            auto s3 = solve2(a, x);
            ans.insert(s3.begin(), s3.end());
        }
        cout << (int)ans.size() << "\n";
        for (int64_t x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
