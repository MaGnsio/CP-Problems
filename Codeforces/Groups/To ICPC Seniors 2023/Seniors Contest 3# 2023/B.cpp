/**
 *    author:  MaGnsi0
 *    created: 06.02.2023 09:15:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("wall.in", "r", stdin);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        reverse(a.begin() + l - 1, a.begin() + r);
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}
