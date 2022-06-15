/**
 *    author:  MaGnsi0
 *    created: 06.03.2022 11:49:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, c;
        cin >> n >> c;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        n = (int)a.size();
        vector<int> f(c + 1, 0);
        for (int i = 0; i < n; ++i) {
            f[a[i]]++;
        }
        for (int i = 1; i <= c; ++i) {
            f[i] += f[i - 1];
        }
        if (a[0] != 1) {
            cout << "NO\n";
            continue;
        }
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            for (int j = a[i]; j <= c; j += a[i]) {
                int l = j, r = min(c, j + a[i] - 1), v = j / a[i];
                if (f[r] - f[l - 1] > 0 && f[v] - f[v - 1] == 0) {
                    ok = false;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
