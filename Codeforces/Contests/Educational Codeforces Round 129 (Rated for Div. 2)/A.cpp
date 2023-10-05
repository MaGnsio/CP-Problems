/**
 *    author:  MaGnsi0
 *    created: 23.05.2022 16:35:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int m;
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        cout << (a[n - 1] >= b[m - 1] ? "Alice" : "Bob") << "\n";
        cout << (b[m - 1] >= a[n - 1] ? "Bob" : "Alice") << "\n";
    }
}
