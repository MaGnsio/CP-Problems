/**
 *    author:  MaGnsi0
 *    created: 19.10.2023 16:56:20
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e16;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<tuple<int, int, int64_t>> a(n);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        int y; cin >> y;
        int c; cin >> c;
        if (x < y) { swap(x, y); }
        a[i] = make_tuple(x, y, c);
    }
    sort(a.begin(), a.end());
    set<int> S; S.insert(0), S.insert(2e9);
    for (auto [x, y, c] : a) {
        S.insert(x);
        S.insert(y);
    }
    map<int, int> I, J;
    for (int x : S) {
        J[(int)I.size()] = x;
        I[x] = (int)I.size();
    }
    int m = (int)I.size();
    vector<int64_t> b(4 * m);
    vector<pair<int64_t, int>> c(4 * m, {OO, m});
    function<void(int)> push = [&](int j) {
        b[2 * j + 1] += b[j];
        b[2 * j + 2] += b[j];
        c[2 * j + 1].first += b[j];
        c[2 * j + 2].first += b[j];
        b[j] = 0;
    };
    function<void(int, int, int)> build = [&](int j, int low, int high) {
        if (low > high) { return; }
        if (low == high) {
            int x = (low == m - 1 ? J[low] + 1 : J[low + 1]);
            c[j] = {-x, J[low]};
        } else {
            int mid = (low + high) / 2;
            build(2 * j + 1, low, mid);
            build(2 * j + 2, mid + 1, high);
            c[j] = min(c[2 * j + 1], c[2 * j + 2]);
        }
    };
    function<void(int, int, int, int, int, int64_t)> update = [&](int j, int low, int high, int l, int r, int64_t add) {
        if (low > high) { return; }
        if (high < l || r < low) { return; }
        if (l <= low && high <= r) {
            c[j].first += add;
            b[j] += add;
        } else {
            push(j);
            int mid = (low + high) / 2;
            update(2 * j + 1, low, mid, l, r, add);
            update(2 * j + 2, mid + 1, high, l, r, add);
            c[j] = min(c[2 * j + 1], c[2 * j + 2]);
        }
    };
    function<pair<int64_t, int>(int, int, int, int, int)> query = [&](int j, int low, int high, int l, int r) {
        if (low > high) { return make_pair(OO, m); }
        if (high < l || r < low) { return make_pair(OO, m); }
        if (l <= low && high <= r) { return c[j]; }
        push(j);
        int mid = (low + high) / 2;
        return min(query(2 * j + 1, low, mid, l, r), query(2 * j + 2, mid + 1, high, l, r));
    };
    int64_t sum = 0, j = 0;
    tuple<int64_t, int, int> ans = make_tuple(0, 2e9, 2e9);
    build(0, 0, m - 1);
    for (int up : S) {
        while (j < n && get<0>(a[j]) <= up) {
            sum += get<2>(a[j]);
            update(0, 0, m - 1, I[get<1>(a[j])], m - 1, get<2>(a[j]));
            j++;
        }
        auto [cost, down] = query(0, 0, m - 1, 0, I[up] - 1);
        if (up == down) { continue; }
        if (cost <= 0) {
            cost = sum - cost - up;
            down = J[I[down] + 1];
        } else {
            cost = sum - up;
            down = 0;
        }
        ans = max(ans, make_tuple(cost, down, up));
    }
    map<int, int64_t> same;
    for (auto [x, y, c] : a) {
        if (x == y) { same[x] += c; }
    }
    for (auto [x, tot] : same) {
        ans = max(ans, make_tuple(tot, x, x));
    }
    cout << get<0>(ans) << "\n";
    cout << get<1>(ans) << " " << get<1>(ans) << " ";
    cout << get<2>(ans) << " " << get<2>(ans);
}
