/**
 *    author:  MaGnsi0
 *    created: 13.06.2022 09:35:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        cout << a[x - 1] - (x == y ? 0 : a[x - y - 1]) << "\n";
    }
}
