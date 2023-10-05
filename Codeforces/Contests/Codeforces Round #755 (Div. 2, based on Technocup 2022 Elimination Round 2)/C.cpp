/**
 *    author:  MaGnsi0
 *    created: 14.11.2021 14:27:44
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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i] || a[i] == b[i] - 1) {
                continue;
            }
            ok = false;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
