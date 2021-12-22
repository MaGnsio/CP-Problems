/**
 *    author:  MaGnsi0
 *    created: 16.12.2021 19:40:24
**/
#include <bits/stdc++.h>

using namespace std;

void compress(vector<int>& a) {
    vector<int> b = a;
    map<int, int> mp;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for (int i = 0; i < (int)b.size(); ++i) {
        mp[b[i]] = i;
    }
    for (int i = 0; i < (int)a.size(); ++i) {
        a[i] = mp[a[i]];
    }
}

struct segment_tree {
    int N;
    vector<int> segTree;
    int L(int p) {
        return (p << 1);
    }
    int R(int p) {
        return (p << 1) + 1;
    }
    int compine(int a, int b) {
        return (a + b);
    }
    int query(int p, int l, int r, int i, int j) {
        if (i > j) {
            return 0;
        }
        if (i <= l && r <= j) {
            return segTree[p];
        }
        int m = (l + r) / 2;
        return compine(query(L(p), l, m, i, min(m, j)), query(R(p), m + 1, r, max(i, m + 1), j));
    }
    void update(int p, int l, int r, int v, int i, int j) {
        if (i > j) {
            return;
        }
        if (l == r) {
            segTree[p] += v;
        } else {
            int m = (l + r) / 2;
            update(L(p), l, m, v, i, min(m, j));
            update(R(p), m + 1, r, v, max(i, m + 1) , j);
            segTree[p] = compine(segTree[L(p)], segTree[R(p)]);
        }
    }
    segment_tree(int n) {
        N = n;
        segTree = vector<int>(4 * n, 0);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    compress(a), compress(b);
    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = {a[i], b[i]};
    }
    sort(c.begin(), c.end(), [](pair<int, int> x, pair<int, int> y) {
            return ((x.first < y.first) || (x.first == y.first && y.second < x.second));
       });
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; ++i) {
        mp[c[i]]++;
    }
    long long res = 0;
    segment_tree st(n);
    for (int i = 0; i < n; ++i) {
        st.update(1, 0, n - 1, 1, c[i].second, c[i].second);
        res += (--mp[c[i]]) + st.query(1, 0, n - 1, c[i].second, n - 1);
    }
    cout << res;
}
