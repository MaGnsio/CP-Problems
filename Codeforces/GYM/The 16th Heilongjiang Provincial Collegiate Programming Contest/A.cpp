/**
 *    author:  MaGnsi0
 *    created: 26.10.2023 14:00:41
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e6;

vector<int> a(N), max_a(N), or_a(N);

void build(int j, int low, int high) {
    if (low > high) { return; }
    if (low == high) {
        max_a[j] = or_a[j] = a[low];
    } else {
        int mid = (low + high) / 2;
        build(2 * j + 1, low, mid);
        build(2 * j + 2, mid + 1, high);
        max_a[j] = max(max_a[2 * j + 1], max_a[2 * j + 2]);
        or_a[j] = or_a[2 * j + 1] | or_a[2 * j + 2];
    }
}

void and_update(int j, int low, int high, int from, int to, int val) {
    if (low > high) { return; }
    if (to < low || high < from) { return; }
    if (from <= low && high <= to && (val & or_a[j]) == or_a[j]) { return; }
    if (low == high) {
        max_a[j] = or_a[j] = (max_a[j] & val);
    } else {
        int mid = (low + high) / 2;
        and_update(2 * j + 1, low, mid, from, to, val);
        and_update(2 * j + 2, mid + 1, high, from, to, val);
        max_a[j] = max(max_a[2 * j + 1], max_a[2 * j + 2]);
        or_a[j] = or_a[2 * j + 1] | or_a[2 * j + 2];
    }
}

void update(int j, int low, int high, int x, int val) {
    if (low > high) { return; }
    if (x < low || high < x) { return; }
    if (low == high) {
        max_a[j] = or_a[j] = val;
    } else {
        int mid = (low + high) / 2;
        update(2 * j + 1, low, mid, x, val);
        update(2 * j + 2, mid + 1, high, x, val);
        max_a[j] = max(max_a[2 * j + 1], max_a[2 * j + 2]);
        or_a[j] = or_a[2 * j + 1] | or_a[2 * j + 2];
    }
}

int query(int j, int low, int high, int from, int to) {
    if (low > high) { return 0; }
    if (to < low || high < from) { return 0; }
    if (from <= low && high <= to) {
        return max_a[j];
    }
    int mid = (low + high) / 2;
    int x = query(2 * j + 1, low, mid, from, to);
    int y = query(2 * j + 2, mid + 1, high, from, to);
    return max(x, y);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(0, 0, n - 1);
    while (m--) {
        string t; cin >> t;
        if (t == "AND") {
            int low; cin >> low; low--;
            int high; cin >> high; high--;
            int val; cin >> val;
            and_update(0, 0, n - 1, low, high, val);
        } else if (t == "UPD") {
            int x; cin >> x; x--;
            int val; cin >> val;
            update(0, 0, n - 1, x, val);
        } else {
            int from; cin >> from; from--;
            int to; cin >> to; to--;
            cout << query(0, 0, n - 1, from, to) << "\n";
        }
    }
}
