/**
 *    author:  MaGnsi0
 *    created: 09.03.2022 17:18:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        string s, t;
        cin >> s >> t;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = (t[i] - s[i] + 26) % 26;
        }
        for (int i = 1; i < n; ++i) {
            a[i] = ((i & 1 ? -a[i] : a[i]) + a[i - 1] + 26) % 26;
        }
        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            int x = (a[r - 1] - (l - 1 ? a[l - 2] : 0));
            cout << (x ? "NO" : "YES") << "\n";
        }
    }
}
