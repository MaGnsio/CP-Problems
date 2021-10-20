/**
 *    author:  MaGnsi0
 *    created: 13/07/2021 03:02:28
**/
#include <bits/stdc++.h>
using namespace std;

void build(vector<int>& a, vector<int>& v, int i, int l, int r) {
    if (l == r) {
        a[i] = v[l];
        return;
    }
    int mid = (l + r) / 2;
    build(a, v, 2 * i + 1, l, mid);
    build(a, v, 2 * i + 2, mid + 1, r);
    a[i] = min(a[2 * i + 1], a[2 * i + 2]);
}

int query(vector<int>& a, int i, int l, int r, int x, int y) {
    if (r < x || y < l) {
        return INT_MAX;
    }
    if (x <= l && r <= y) {
        return a[i];
    }
    int mid = (l + r) / 2;
    return min(query(a, 2 * i + 1, l, mid, x, min(y, mid)), query(a, 2 * i + 2, mid + 1, r, max(x, mid + 1), y));
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    vector<int> a(4 * n, INT_MAX);
    build(a, v, 0, 0, n - 1);
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << query(a, 0, 0, n - 1, x, y) << "\n";
    }
    
}
