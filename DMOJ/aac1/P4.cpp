/**
 *    author:  MaGnsi0
 *    created: 30.03.2023 22:28:54
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> b(N);
    for (int i = 0; i < n; ++i) {
        b[a[i]].push_back(i);
    }
    function<bool(int, int, int)> found = [&](int x, int l, int r) {
        auto it = lower_bound(b[x].begin(), b[x].end(), l);
        return (it != b[x].end() && *it <= r);
    };
    for (int i = 0; i < q; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        bool ok = false;
        for (int j = 1; j * j < x; ++j) {
            if (x % j) { continue; }
            ok |= found(j, l - 1, r - 1) && found(x / j, l - 1, r - 1);
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
