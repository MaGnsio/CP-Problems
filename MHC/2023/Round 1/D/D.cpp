/**
 *    author:  MaGnsi0
 *    created: 08.10.2023 15:19:59
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e9 + 7;

struct node {
    pair<int, int> F1;
    pair<int, int> F2;
    node() {
        F1 = F2 = make_pair(-OO, -OO);
    }
    node(int x, int i) {
        F1 = make_pair(x, -i);
        F2 = make_pair(OO - x, -i);
    }
};

node F(node x, node y) {
    node res;
    res.F1 = max(x.F1, y.F1);
    res.F2 = max(x.F2, y.F2);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> c(4 * n);
        vector<node> b(4 * n);
        function<void(int)> push = [&](int j) {
            c[2 * j + 1] ^= c[j];
            c[2 * j + 2] ^= c[j];
            if (c[j]) {
                swap(b[2 * j + 1].F1, b[2 * j + 1].F2);
                swap(b[2 * j + 2].F1, b[2 * j + 2].F2);
            }
            c[j] = 0;
        };
        function<void(int, int, int)> build = [&](int j, int low, int high) {
            if (low > high) { return; }
            if (low == high) {
                b[j] = node(a[low], low);
                return;
            }
            int mid = (low + high) / 2;
            build(2 * j + 1, low, mid);
            build(2 * j + 2, mid + 1, high);
            b[j] = F(b[2 * j + 1], b[2 * j + 2]);
        };
        build(0, 0, n - 1);
        function<void(int, int, int, int, int)> update = [&](int j, int low, int high, int from, int to) {
            if (low > high) { return; }
            if (high < from || low > to) { return; }
            if (from <= low && high <= to) {
                swap(b[j].F1, b[j].F2);
                c[j] ^= 1;
            } else {
                push(j);
                int mid = (low + high) / 2;
                update(2 * j + 1, low, mid, from, to);
                update(2 * j + 2, mid + 1, high, from, to);
                b[j] = F(b[2 * j + 1], b[2 * j + 2]);
            }
        };
        function<node(int, int, int, int, int)> query = [&](int j, int low, int high, int from, int to) {
            if (low > high) { return node(); }
            if (high < from || low > to) { return node(); }
            if (from <= low && high <= to) {
                return b[j];
            }
            push(j);
            int mid = (low + high) / 2;
            return F(query(2 * j + 1, low, mid, from, to), query(2 * j + 2, mid + 1, high, from, to));
        };
        int Q; cin >> Q;
        int64_t ans = 0;
        while (Q--) {
            int from, to;
            cin >> from >> to;
            update(0, 0, n - 1, from - 1, to - 1);
            ans += 1 - query(0, 0, n - 1, 0, n - 1).F1.second;
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
