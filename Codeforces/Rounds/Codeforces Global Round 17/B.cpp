/**
 *    author:  MaGnsi0
 *    created: 24.11.2021 14:35:10
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
        int x = -1, y = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] != a[n - i - 1]) {
                x = a[i];
                y = a[n - i - 1];
            }
        }
        vector<int> b, c;
        for (int i = 0; i < n; ++i) {
            if (a[i] != x) {
                b.push_back(a[i]);
            }
            if (a[i] != y) {
                c.push_back(a[i]);
            }
        }
        auto ok = [](vector<int> a) {
            int m = (int)a.size();
            for (int i = 0; i < m; ++i) {
                if (a[i] != a[m - i - 1]) {
                    return false;
                }
            }
            return true;
        };
        cout << (ok(b) || ok(c) ? "YES" : "NO") << "\n";
    }
}
